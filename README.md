# mami-exam-vulpix
VULnerable Payment application X


## Установка
1. Скопировать себе репозиторий
2. Поставить `php-fpm`, `php-mysql`, `php-gd2`,`php-mbstring`,`php-xml`,`php-curl`, `nginx`
3. Настроить nginx и php (стандартные настройки)
4. Выполнить composer install
5. Зайти в папку phpMyAdmin и выполнить `../composer.phar install`

vendor/phpmyadmin/phpmyadmin$ ../../../composer.phar install
## Как зайти
Тестовый логин и пароль - ivanov/1

## Какие есть уязвимости

**Не читайте, пока не попробовали взломать!!!**

* уязвимая капча - код для неё явно передаётся в картинку и ставится в куки
* SQL injection в поле суммы платежа
* папка backup с данными пользователей и данными по транзакциям
* папка phpMyAdmin с настроенной авторизацией
* открытые данные composer
* загрузка в директорию tmp как пережатых, так и исходных файлов
