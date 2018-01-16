<nav class="navbar navbar-inverse navbar-fixed-top">
    <div class="container">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar"
                    aria-expanded="false" aria-controls="navbar">
                <span class="sr-only">Меню</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand" href="#">Vulpix</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
            <?
            $userId = getUserId($_COOKIE['session']);
            if (file_exists('uploads/' . $userId . '.png')) {
                echo '<img src="uploads/' . $userId . '.png" style="max-width:50px;max-height:50px;">';
            } ?>
            <ul class="nav navbar-nav">
                <li class="active"><a href="/">Главная</a></li>
                <li><a href="?page=profile">Профиль</a></li>
                <li><a href="#logout" onclick="logout()">Выйти</a></li>
            </ul>
        </div><!--/.nav-collapse -->
    </div>
</nav>