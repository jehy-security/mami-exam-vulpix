<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en-US">

<head profile="http://gmpg.org/xfn/11">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Vulpix</title>
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="/vendor/twbs/bootstrap/dist/css/bootstrap.min.css">

    <!-- Optional theme -->
    <link rel="stylesheet" href="/vendor/twbs/bootstrap/dist/css/bootstrap-theme.min.css">

    <!-- Latest compiled and minified JavaScript -->
    <script type="text/javascript" src="/vendor/components/jquery/jquery.min.js"></script>
    <script type="text/javascript" src="/vendor/twbs/bootstrap/dist/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="/js/common.js"></script>
    <? if ($file === 'login') { ?>
        <script type="text/javascript" src="/js/login.js"></script>
    <link rel="stylesheet" href="/css/login.css"><? }
    else {
    if ($file === 'profile')
    {
    ?>
    <link rel="stylesheet" href="/css/profile.css">
        <script type="text/javascript" src="/js/profile.js"></script><?
    }
    ?>
    <link rel="stylesheet" href="/css/inner.css"><?
    } ?>
</head>

<body>
<? if ($file !== 'login') require_once('menu.inc'); ?>