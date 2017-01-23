<?

function getUserId($token)
{
    global $mysqli;
    $sql = 'SELECT id FROM users u WHERE token=?';
    $stmt = $mysqli->prepare($sql);
    $r = $stmt->bind_param('s', $token);
    $res = $stmt->execute();
    $result = $stmt->get_result();
    if (!$mysqli->affected_rows)
        return false;
    $row = $result->fetch_array(MYSQLI_ASSOC);
    return $row['id'];
}

function getCard($userId)
{
    global $mysqli;

    $sql = 'SELECT c.id FROM credit_cards c WHERE user_id=?';
    $stmt = $mysqli->prepare($sql);
    $r = $stmt->bind_param('i', $userId);
    $res = $stmt->execute();
    $result = $stmt->get_result();
    if (!$mysqli->affected_rows)
        return false;
    $row = $result->fetch_array(MYSQLI_ASSOC);
    return $row['id'];
}
?>