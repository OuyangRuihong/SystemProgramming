#!/bin/bash
Max=0
MaxString=0

function Fliter() {
    FliterFile=$1
    grep -q -w "text" ${FliterFile}
    if [[ $? -eq 0  ]]; then
        echo 0
    else
        echo 1
}

function findfile(){
    File = $1
    for i in 'cat ${File} | tr -c -s "a-zA-Z" "\n"';do
        echo $i
        if [[ ${Max} -lt ${#i} ]];then
            Max=${#i}
            MaxString=${i}
        fi
    done
    printf "MaxString=%s Max=%d" ${MaxString} ${Max}
}

function FindDir(){
    for i in `ls -A ${Dirname}`;do
        if[[ -d ${i} ]]; then
        FindDir ${Dirname}/${i}
    elif [[ -f ${i} ]]; then
        check='Fliter ${Dirname}/${1}'
        if [[  ]]
            findfile ${Dirname}/${i}
    done

}

if [[ -d $1 ]]; then
    FindDir $1
elif [[ -f $1 ]]; then
    check='FliterFile $1'
    if [[ ${check} -eq 0 ]]; then


