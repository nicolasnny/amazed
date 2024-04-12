#!/usr/bin/env bash
##
## EPITECH PROJECT, 2024
## functional
## File description:
## functional test
##

echo " _____                 _   _                   _   _____         _            "
echo "|  ___|   _ _ __   ___| |_(_) ___  _ __   __ _| | |_   _|__  ___| |_ ___ _ __ "
echo "| |_ | | | | '_ \ / __| __| |/ _ \| '_ \ / _\` | |   | |/ _ \/ __| __/ _ \ '__|"
echo "|  _|| |_| | | | | (__| |_| | (_) | | | | (_| | |   | |  __/\__ \ ||  __/ |   "
echo "|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|\__,_|_|   |_|\___||___/\__\___|_|   "
echo ""

##working map
../amazed < good_map > good_map_output 2>&1

if diff -q good_map_correct good_map_output >/dev/null; then
    echo -e "\e[32m[FUNCTIONAL] Working Map Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] Working Map Test NOT PASSED\e[0m"
fi

##no robots
../amazed < no_robots
if [ $? -eq 84 ]; then
    echo -e "\e[32m[FUNCTIONAL] No Robots Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No Robots Test NOT PASSED\e[0m"
fi


##no correct path
../amazed < no_correct_path > no_correct_path_output 2>&1
if diff -q no_correct_path_correct no_correct_path_output >/dev/null; then
    echo -e "\e[32m[FUNCTIONAL] No Correct Path Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No Correct Path Test NOT PASSED\e[0m"
fi

##no connection
../amazed < no_connection > no_connection_output 2>&1
if [ $? -eq 84 ] && diff -q no_connection_output no_connection_correct >/dev/null; then
    echo -e "\e[32m[FUNCTIONAL] No Connection Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No Connection Test NOT PASSED\e[0m"
fi

##no room
../amazed < no_room > no_room_output 2>&1
if [ $? -eq 84 ] && diff -q no_room_correct no_room_output >/dev/null; then
    echo -e "\e[32m[FUNCTIONAL] No Room Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No Room Test NOT PASSED\e[0m"
fi

##no end
../amazed < no_end
if [ $? -eq 84 ]; then
    echo -e "\e[32m[FUNCTIONAL] No End Room Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No End Room Test NOT PASSED\e[0m"
fi

##no start
../amazed < no_start
if [ $? -eq 84 ]; then
    echo -e "\e[32m[FUNCTIONAL] No Start Room Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] No Start Room Test NOT PASSED\e[0m"
fi

##empty
../amazed < empty
if [ $? -eq 84 ]; then
    echo -e "\e[32m[FUNCTIONAL] Empty Path Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] Empty File Test NOT PASSED\e[0m"
fi

##wrong args
../amazed WithArg
if [ $? -eq 84 ]; then
    echo -e "\e[32m[FUNCTIONAL] Wrong Args Test PASSED\e[0m"
else
    echo -e "\e[31m[FUNCTIONAL] Wrong Args Test NOT PASSED\e[0m"
fi
