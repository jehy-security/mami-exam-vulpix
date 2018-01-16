-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Хост: localhost
-- Время создания: Янв 17 2017 г., 02:01
-- Версия сервера: 5.5.52-MariaDB
-- Версия PHP: 5.5.38

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `vulpix`
--

-- --------------------------------------------------------

--
-- Структура таблицы `credit_cards`
--

CREATE TABLE `credit_cards` (
  `id` int(10) UNSIGNED NOT NULL,
  `user_id` int(10) UNSIGNED NOT NULL,
  `card_number` varchar(40) NOT NULL,
  `cvv` int(4) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `credit_cards`
--

INSERT INTO `credit_cards` (`id`, `user_id`, `card_number`, `cvv`) VALUES
(1, 1, '4716236879336474', 1045),
(2, 2, '4929601765601716', 346),
(3, 3, '5435207684682862', 1845),
(4, 4, '341900725574494', 624),
(5, 5, '378636618972793', 812),
(6, 6, '343694576273797', 345),
(7, 7, '347432884296630', 283),
(8, 8, '343943089410838', 127),
(9, 9, '378923623209654', 383);

-- --------------------------------------------------------

--
-- Структура таблицы `transactions`
--

CREATE TABLE `transactions` (
  `id` int(10) UNSIGNED NOT NULL,
  `card_from` int(10) UNSIGNED NOT NULL,
  `card_to` int(10) UNSIGNED NOT NULL,
  `amount` int(10) UNSIGNED NOT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `transactions`
--

INSERT INTO `transactions` (`id`, `card_from`, `card_to`, `amount`, `description`) VALUES
(1, 1, 2, 30, 'за обед'),
(2, 2, 1, 30, 'за услуги'),
(14, 3, 4, 100, 'розы'),
(15, 4, 5, 400, 'долги'),
(16, 5, 6, 80, 'за лопату'),
(17, 6, 7, 12, 'за проезд'),
(18, 7, 8, 5000, 'кварплата'),
(19, 8, 9, 20000, 'ремонт машины'),
(20, 9, 3, 1000000, 'выигрыш в лотерею'),
(21, 8, 4, 5000, 'штраф за парковку'),
(22, 7, 4, 300, 'за обед'),
(23, 6, 5, 2000, 'просто так'),
(24, 8, 1, 100, 'за красивые глаза'),
(25, 7, 2, 50, 'пожертвование'),
(26, 6, 4, 10, 'компенсация морального ущерба'),
(27, 3, 7, 50, 'краудфандинг');

-- --------------------------------------------------------

--
-- Структура таблицы `users`
--

CREATE TABLE `users` (
  `id` int(10) UNSIGNED NOT NULL,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `token` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`id`, `login`, `password`, `name`, `token`) VALUES
(1, 'ivanov', 'c4ca4238a0b923820dcc509a6f75849b', 'Иванов Иван Иванович', '8924e749d58795432869c0a2d0bed81c'),
(2, 'petrov', 'c81e728d9d4c2f636f067f89cc14862c', 'Петров Пётр', '13d15372e65023545c4096d8d20fa472'),
(3, 'sidorova', 'eccbc87e4b5ce2fe28308fd9f2a7baf3', 'Сидорова Иннокентия', NULL),
(4, 'gagarin', 'gagarin', 'Гагарин', NULL),
(5, 'lenin', 'lenin1212', 'Ленин Владимир', NULL),
(6, 'sokolov', 'sokol', 'Иван Соколов', NULL),
(7, 'novikov', 'nova', 'Пётр Новиков', NULL),
(8, 'komarov', 'kk', 'Илья Комаров', NULL),
(9, 'ilin', 'nili', 'Семён Ильин', NULL);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `credit_cards`
--
ALTER TABLE `credit_cards`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `transactions`
--
ALTER TABLE `transactions`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `credit_cards`
--
ALTER TABLE `credit_cards`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT для таблицы `transactions`
--
ALTER TABLE `transactions`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;
--
-- AUTO_INCREMENT для таблицы `users`
--
ALTER TABLE `users`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
