#!/bin/bash

tmpdir=$(mktemp -d)

git clone --depth 1 --recursive --shallow-submodules -b master https://github.com/Hun1eR/CSSDK.git $tmpdir
ret=$?

if test "$ret" -eq 0
then
    echo
    echo 'Commit:' $(git -C $tmpdir log -1 --format='%H')
    echo 'Author:' $(git -C $tmpdir log -1 --format='%an, %ar')
    echo 'Subject:' $(git -C $tmpdir log -1 --format='%s')
    echo

    mkdir -p "../sdk"
    ret=$?

    if test "$ret" -eq 0
    then
        echo 'Updating CSSDK...'
        cp -rf "$tmpdir/cssdk" "../sdk"
        ret=$?

        if test "$ret" -eq 0
        then
            echo 'Successfully completed.'
        fi
    fi
fi

rm -rf $tmpdir

echo
read -p 'Press [Enter] key to exit...'
