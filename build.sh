#!/bin/bash

#ENV_VAR_FILE="setenv.sh"
#
#if [ ! -f $ENV_VAR_FILE ];
#then
#    WORK_DIR=${PWD}
#    NEW_FILE_PATH=${PWD}/$ENV_VAR_FILE
#    DDS_VARS=$(readlink -f ../third-party-build/DDS/setenv.sh)
#    MOOS_VARS=$(readlink -f ../third-party-build/moos-ivp/setenv.sh)
#
#    echo "source ${DDS_VARS}" > ${ENV_VAR_FILE}
#    echo "source ${MOOS_VARS}" >> ${ENV_VAR_FILE}
#    echo 'export PATH=${PATH}:'${WORK_DIR}'/bin' >> ${ENV_VAR_FILE}
#    echo 'export PATH=${PATH}:'${WORK_DIR}'/bin' >> ${ENV_VAR_FILE}
#    #echo 'export QTDIR=/usr/share/qt4' >> ${ENV_VAR_FILE}
#    chmod +x ${ENV_VAR_FILE}
#    
#    echo "-----------------------------------------------------"
#    echo "Generated environment file"
#    echo "Add the following to your .bashrc file for future use"
#    echo "        source ${NEW_FILE_PATH}"
#fi
#
#source $ENV_VAR_FILE

if [ ! -d ./build ];
then
mkdir ./build
fi

pushd ./build >& /dev/null

cmake ..
make $@

popd >& /dev/null
