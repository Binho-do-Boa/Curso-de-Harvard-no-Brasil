-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2020 AND street = 'Chamberlin Street';
SELECT * FROM interviews WHERE transcript LIKE '%courthouse%';
SELECT * FROM atm_transactions WHERE atm_location = 'Fifer Street' AND transaction_type = 'withdraw' AND year = '2020' AND month = '7' AND day = '28';
SELECT * FROM phone_calls WHERE duration < 60 AND year = '2020' AND month = '7' AND day = '28';
