#!/bin/sh

CURRENT_DATE=$(date +%d-%m-%Y)
LOG_GREEN='\033[1;32m'
LOG_NOCOLOR='\033[0m'

git add . &>/dev/null
echo "\t––––––––––––––––––––––––––––––––––––––––––––"
echo "\tCurrent DATE = $CURRENT_DATE\n"
echo "\t${LOG_GREEN}██${LOG_NOCOLOR} Check ADD = OK"
git commit -m "$CURRENT_DATE" &>/dev/null
echo "\t${LOG_GREEN}██${LOG_NOCOLOR} Check COMMIT = OK"
git push &>/dev/null
echo "\t${LOG_GREEN}██${LOG_NOCOLOR} Check PUSH = OK"
echo "\t––––––––––––––––––––––––––––––––––––––––––––"
