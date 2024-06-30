#!/bin/bash

# 批量运行程序
for fileNumber in {241..520}; do
  echo "Running with file number: $fileNumber"
   root -l -q "add152.C($fileNumber)"
   root -l -q "add30.C($fileNumber)"

  if [ $? -ne 0 ]; then
    echo "Error running script with file number $fileNumber"
  fi
done
