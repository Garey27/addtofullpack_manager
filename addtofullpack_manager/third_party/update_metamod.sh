#!/bin/bash

tmpdir=$(mktemp -d)

git clone --depth 1 --recursive --shallow-submodules -b master https://github.com/Hun1eR/Metamod-SDK.git $tmpdir
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
        echo 'Updating Metamod SDK...'

        if test -f "../sdk/metamod/include/metamod/metamod_config.h"
        then
            rm -f "$tmpdir/metamod/include/metamod/metamod_config.h"
        fi

        cp -rf "$tmpdir/metamod" "../sdk"
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
