<?

if ($_REQUEST['name']) {
    $sql = 'update users set name="' . $_REQUEST['name'] . '" where id=' . $userId;
    $stmt = $mysqli->prepare($sql);
    $res = $stmt->execute();
}

$sql = 'SELECT id FROM users u WHERE token="' . $_COOKIE['session'] . '"';
$stmt = $mysqli->prepare($sql);
$res = $stmt->execute();
$result = $stmt->get_result();
$row = $result->fetch_array(MYSQLI_ASSOC);
$userId = $row['id'];

$sql = 'SELECT name FROM users WHERE id=?';
$stmt = $mysqli->prepare($sql);
$r = $stmt->bind_param('i', $userId);
$res = $stmt->execute();
$result = $stmt->get_result();
$array = $result->fetch_all(MYSQLI_ASSOC);
$userName = $array[0]['name'];

function resize_image_max($image, $max_width, $max_height)
{
    $w = imagesx($image); //current width
    $h = imagesy($image); //current height
    if ((!$w) || (!$h)) {
        $GLOBALS['errors'][] = 'Image couldn\'t be resized because it wasn\'t a valid image.';
        return false;
    }
    if (($w <= $max_width) && ($h <= $max_height)) {
        return $image;
    } //no resizing needed
    //try max width first...
    $ratio = $max_width / $w;
    $new_w = $max_width;
    $new_h = $h * $ratio;

    //if that didn't work
    if ($new_h > $max_height) {
        $ratio = $max_height / $h;
        $new_h = $max_height;
        $new_w = $w * $ratio;
    }
    $new_image = imagecreatetruecolor($new_w, $new_h);
    imagecopyresampled($new_image, $image, 0, 0, 0, 0, $new_w, $new_h, $w, $h);
    return $new_image;
}

if (is_uploaded_file($_FILES['image']['tmp_name'])) {
    $mimetype = mime_content_type($_FILES['image']['tmp_name']);
    if (in_array($mimetype, array('image/png', 'image/gif', 'image/jpeg'))) {
        $tmpName = getcwd() . '/tmp/' . $_FILES['image']['name'];
        move_uploaded_file($_FILES['image']['tmp_name'], $tmpName);
        $img = imagecreatefromstring(file_get_contents($tmpName));
        $img = resize_image_max($img, 200, 200);
        imagepng($img, 'uploads/' . $userId . '.png');
        echo '<div class="alert alert-success" role="alert">Аватар успешно загружен!</div>';
    } else {
        echo '<div class="alert alert-danger" role="alert">Загружен неправильный тип файла!</div>';
    }
}
?>


<div class="container">
    <h1>Редактирование профиля</h1>
    <div class="col-md-6">
        <div class="form-group">

            <form action="index.php" enctype="multipart/form-data" method="post">
                <input type="hidden" name="page" value="profile">


                <div class="form-group">
                    <label for="name">Ваше имя:</label><input class="form-control" type="text" name="name" id="name"
                                                              value="<?= $userName; ?>">
                </div>

                <label>Загрузить аватар (с ним же веселее!)</label>
                <div class="input-group">
            <span class="input-group-btn">
                <span class="btn btn-default btn-file">
                    Обзор… <input type="file" id="imgInp" name="image">
                </span>
            </span>
                    <input type="text" class="form-control" readonly>
                </div>
                <img id='img-upload'/ <? if (file_exists('uploads/' . $userId . '.png')) {
                    echo ' src="uploads/' . $userId . '.png"';
                } ?>>
                <input type="submit" class="btn btn-primary btn-lg btn-block" value="Сохранить">
            </form>
        </div>
    </div>
</div>