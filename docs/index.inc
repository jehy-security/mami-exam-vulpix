<?

include_once('utils.php');

$userId = getUserId($_COOKIE['session']);


if ($_REQUEST['action'] === 'transfer') {
    $card_from = getCard($userId);
    $card_to = getCard($_REQUEST['to']);
    if (!$card_to) {
        echo '<div class="alert alert-danger" role="alert">Получатель не найден!</div>';
    } elseif ($_REQUEST['captcha'] !== $_REQUEST['captchaCheck']) {
        echo '<div class="alert alert-danger" role="alert">Неправильно введён текст с картинки!</div>';
    } else {
        //TODO: cast $_REQUEST['amount'] to int
        $sql = 'INSERT INTO transactions(card_from, card_to, amount, description) VALUES(?,?,"' . $_REQUEST['amount'] . '",?)';
        $stmt = $mysqli->prepare($sql);
        $stmt->bind_param('iis', $card_from, $card_to, $_REQUEST['description']);
        $res = $stmt->execute();
        echo '<div class="alert alert-success" role="alert">Ура, перевод прошёл!</div>';
    }
}
?>


<div class="container">
    <h1>Ваши друзья</h1>
    <ul class="list-group">

        <?
        $sql = 'SELECT id, name FROM users WHERE id<>?';
        $stmt = $mysqli->prepare($sql);
        $r = $stmt->bind_param('i', $userId);
        $res = $stmt->execute();
        $result = $stmt->get_result();
        $array = $result->fetch_all(MYSQLI_ASSOC);
        foreach ($array as $one) {
            echo '<li class="list-group-item">' . $one['name'] . '</li>';
        }
        ?>
    </ul>
    <h1>Ваши переводы</h1>
    <table class="table table-striped">
        <thead>
        <tr>
            <th>Сколько</th>
            <th>Описание</th>
            <th>От кого</th>
            <th>Кому</th>
        </tr>
        </thead>
        <tbody>
        <?
        $sql = 'SELECT t.amount,t.description,u_from.name from_user,u_to.name to_user FROM transactions t, users u_from, users u_to WHERE
 t.card_from=u_from.id AND t.card_to=u_to.id AND (u_from.id=? OR u_to.id=?)';
        $stmt = $mysqli->prepare($sql);
        $r = $stmt->bind_param('ii', $userId, $userId);
        $res = $stmt->execute();
        $result = $stmt->get_result();
        $array = $result->fetch_all(MYSQLI_ASSOC);
        foreach ($array as $one) {
            echo '<tr><td>' . $one['amount'] . '</td><td>' . $one['description'] . '</td><td>' . $one['from_user'] . '</td><td>' . $one['to_user'] . '</td></tr>';
        }
        ?></tbody>
    </table>

    <h1>Сделать перевод</h1>
    <form class="col-xs-5" action="index.php" method="post">
        <input type="hidden" name="page" value="index">
        <input type="hidden" name="action" value="transfer">
        <input type="hidden" name="from" value="<?= $userId; ?>">
        <div class="form-group">
            <label for="to">Кому:</label>
            <select class="form-control" name="to" id="to">
                <?
                $sql = 'SELECT id, name FROM users WHERE id<>?';
                $stmt = $mysqli->prepare($sql);
                $r = $stmt->bind_param('i', $userId);
                $res = $stmt->execute();
                $result = $stmt->get_result();
                $array = $result->fetch_all(MYSQLI_ASSOC);
                foreach ($array as $one) {
                    echo '<option value="' . $one['id'] . '">' . $one['name'] . '</li>';
                } ?>

            </select></div>
        <div class="form-group">
            <label for="amount">Сколько:</label><input class="form-control" type="text" name="amount" id="amount"></div>
        <div class="form-group">
            <label for="description">Назначение платежа:</label>
            <textarea class="form-control" name="description" id="description"></textarea>
        </div>
        <?
        $captchaText = generateRandomString(5);
        ?>
        <input type="hidden" name="captchaCheck" value="<?= $captchaText; ?>">
        <div class="form-group">
            <label for="captcha">Введите текст с картинки:</label>
            <img src="captcha.php?text=<?= $captchaText; ?>">
            <input class="form-control" type="text" name="captcha" id="captcha"></div>
        <input type="submit" class="btn btn-primary btn-lg btn-block" value="Перевести">
    </form>

</div><!-- /.container -->
