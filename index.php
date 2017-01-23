<?php
/**
 * Created by PhpStorm.
 * User: Jehy
 * Date: 16.01.2017
 * Time: 21:51
 */

function getPage($file)
{
    if (!$_COOKIE['session'])
        return 'login';
    else if (file_exists($file . '.inc')) {
        return $file;
    }
    return 'index';
}

require_once('db.php');
require_once('common.inc');
$page = $_REQUEST['page'];
$file = getPage($page);
require_once('head.inc');
require_once($file . '.inc');
require_once('footer.inc');

?>