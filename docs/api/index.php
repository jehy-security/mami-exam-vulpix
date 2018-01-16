<?
chdir('../');
header('Content-Type: text/html; charset=utf-8');

require_once('db.php');
require_once('common.inc');
function json_ru_encode($smth)
{
    return json_encode($smth, JSON_UNESCAPED_UNICODE);
}

$action = $_REQUEST['action'];
//damn insecure login
if ($action === 'login') {
    $token = md5($_REQUEST['login']);
    $sql = 'SELECT 1 from users WHERE login=? AND password=MD5(?)';
    $stmt = $mysqli->prepare($sql);
    $r = $stmt->bind_param('ss',$_REQUEST['login'], $_REQUEST['password']);
    $res = $stmt->execute();
    $result = $stmt->get_result();
    // $array = $result->fetch_all(MYSQLI_ASSOC);
    $row_cnt = $result->num_rows;
    if(!$row_cnt)
    {
        $json = json_ru_encode(['error' => 'could bot log in']);
    }
    else
    {
        $sql = 'UPDATE users SET token=? WHERE login=? AND password=MD5(?)';
        $stmt = $mysqli->prepare($sql);
        if (!$stmt)
            die("Error preparing query:" . $mysqli->error);
        $r = $stmt->bind_param('sss', $token, $_REQUEST['login'], $_REQUEST['password']);
        $res = $stmt->execute();
        if (!$res)
            die("Error executing query:" . $mysqli->error);
        header('Content-Type: application/json');
        $json = json_ru_encode(['token' => $token]);
        echo $json;
    }
} else if ($action === 'transactions') {
    $userId = getUserId($_REQUEST['token']);
    if ($userId) {
        $sql = 'SELECT t.amount,t.description,u_from.name from_user,u_to.name to_user FROM transactions t, users u_from, users u_to WHERE
 t.card_from=u_from.id AND t.card_to=u_to.id AND (u_from.id=? OR u_to.id=?)';
        $stmt = $mysqli->prepare($sql);
        $r = $stmt->bind_param('ii', $userId, $userId);
        $res = $stmt->execute();
        $result = $stmt->get_result();
        $array = $result->fetch_all(MYSQLI_ASSOC);
        $json = json_ru_encode($array);
        echo $json;
    } else {
        die(json_ru_encode(['status' => 'error', 'msg' => 'invalid token']));
    }
} else if ($action === 'get_friends') {
    $userId = getUserId($_REQUEST['token']);
    if ($userId) {
        $sql = 'SELECT id, name FROM users WHERE id<>?';
        $stmt = $mysqli->prepare($sql);
        $r = $stmt->bind_param('i', $userId);
        $res = $stmt->execute();
        $result = $stmt->get_result();
        $array = $result->fetch_all(MYSQLI_ASSOC);
        $json = json_ru_encode($array);
        echo $json;
    } else
        die(json_ru_encode(['status' => 'error', 'msg' => 'invalid token']));
} else if ($action === 'transfer') {
    $userId = getUserId($_REQUEST['token']);
    if ($userId) {
        $card_from = getCard($userId);
        $card_to = getCard($_REQUEST['to']);
        if (!$card_to)
            die(json_encode(['status' => 'error', 'msg' => 'recipient not found']));

        $sql = 'INSERT INTO transactions(card_from, card_to, amount, description) VALUES(?,?,?,?)';
        $stmt = $mysqli->prepare($sql);
        $stmt->bind_param('iids', $card_from, $card_to, $_REQUEST['amount'], $_REQUEST['description']);
        $res = $stmt->execute();
        if ($stmt->error)
            die(json_ru_encode(['status' => 'error', 'msg' => 'mysql error:' . $stmt->error]));
        if ($res)
            echo json_ru_encode(['status' => 'ok']);
        else
            echo json_ru_encode(['status' => 'error', 'msg' => $mysqli->error]);
    } else
        die(json_ru_encode(['status' => 'error', 'msg' => 'invalid token']));
} else
    die(json_ru_encode(['status' => 'error', 'msg' => 'no action specified']));
?>
