cd docs
chmod 770 tmp
./composer.phar update
./composer.phar install
cd vendor/phpmyadmin/phpmyadmin
../../../composer.phar update
../../../composer.phar install
cd ../../../
cp ./phpMyAdmin/config.inc.php vendor/phpmyadmin/phpmyadmin/config.inc.php
