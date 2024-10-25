#!/bin/bash

function prompt_user() {
    echo "Enter source dir"
    read source
    echo "Enter dest dir"
    read dest
    echo "Enter backup file name"
    read backup

    tar -czf "$backup.tar.gz" "$source" 
    mv $backup.tar.gz $dest
}
prompt_user
create_backup