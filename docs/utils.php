<?
function generateRandomString($length = 10)
{
    $characters = '23456789abcdefghijkmnpqrstuvwxyz';
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, strlen($characters) - 1)];
    }
    return $randomString;
}
?>
