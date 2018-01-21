#!/bin/sh
#exec > /dev/null 2>&1
#echo  "Compilation en cours..."
#echo "Veuillez patientez..."

set -e

function delay()
{
    sleep 0.2;
}
echo 
echo  "    Compilation en cours..."
echo =============================

CURRENT_PROGRESS=0
function progress()
{
    PARAM_PROGRESS=$1;
    PARAM_PHASE=$2;

    if [ $CURRENT_PROGRESS -le 0 -a $PARAM_PROGRESS -ge 0 ]  ; then echo -ne " ..................... (0%)  $PARAM_PHASE \r"  ; delay; fi;
	if [ $CURRENT_PROGRESS -le 5 -a $PARAM_PROGRESS -ge 5 ]  ; then echo -ne " \033[41m \033[0m\033[41m \033[0m.................... (5%)  $PARAM_PHASE \r"  ; delay; fi;
    
	if [ $CURRENT_PROGRESS -le 10 -a $PARAM_PROGRESS -ge 10 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m................... (10%) $PARAM_PHASE \r"  ; delay; fi;
    rm -rf build
	mkdir build
	if [ $CURRENT_PROGRESS -le 15 -a $PARAM_PROGRESS -ge 15 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m.................. (15%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 20 -a $PARAM_PROGRESS -ge 20 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m................. (20%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 25 -a $PARAM_PROGRESS -ge 25 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m................ (25%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 30 -a $PARAM_PROGRESS -ge 30 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m............... (30%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 35 -a $PARAM_PROGRESS -ge 35 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m.............. (35%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 40 -a $PARAM_PROGRESS -ge 40 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m............. (40%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 45 -a $PARAM_PROGRESS -ge 45 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m............ (45%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 50 -a $PARAM_PROGRESS -ge 50 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m.......... (50%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 55 -a $PARAM_PROGRESS -ge 55 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m.......... (55%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 60 -a $PARAM_PROGRESS -ge 60 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m......... (60%) $PARAM_PHASE \r"  ; delay; fi;
    cd build
    cmake .. 2>&1 >/dev/null
	if [ $CURRENT_PROGRESS -le 65 -a $PARAM_PROGRESS -ge 65 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m........ (65%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 70 -a $PARAM_PROGRESS -ge 70 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m...... (70%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 75 -a $PARAM_PROGRESS -ge 75 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m..... (75%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 80 -a $PARAM_PROGRESS -ge 80 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m.... (80%) $PARAM_PHASE \r"  ; delay; fi;
    make 2>&1 >/dev/null
	if [ $CURRENT_PROGRESS -le 85 -a $PARAM_PROGRESS -ge 85 ]; then echo -en " \033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m\033[41m \033[0m... (90%) $PARAM_PHASE \r"  ; delay; fi;
    if [ $CURRENT_PROGRESS -le 90 -a $PARAM_PROGRESS -ge 90 ]; then echo -en " \033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m\033[42m \033[0m (100%) $PARAM_PHASE \r \n" ; delay; fi;
	if [ $CURRENT_PROGRESS -le 100 -a $PARAM_PROGRESS -ge 100 ];then echo -en '    Compilation Terminée                                          \n' ; delay; fi;

    CURRENT_PROGRESS=$PARAM_PROGRESS;

}


 # echo off
progress 100

echo
