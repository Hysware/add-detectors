#!/bin/bash

# 新建一个整数数组
int_array=(246 252 261 271 283 289 297 309 316 324 338 347 354 367 375 382 394 405 412 421 426 440)

# 打印数组中的所有元素
# echo "Array fileNumbers:"
for fileNumber in "${int_array[@]}"; do
    echo "$fileNumber"
    root -l -q "find_channel.C($fileNumber)"
done


