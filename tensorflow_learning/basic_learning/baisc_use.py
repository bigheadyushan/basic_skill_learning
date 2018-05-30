#!/usr/bin/python
# -*- coding: gbk -*-


import tensorflow as tf
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
###############################
#综述
#计算图
#构建图
#在一个会话中启动图
#交互式使用
#tensor
#变量
#fetch
#feed
###############################

    
    
matrix1 = tf.constant([[3, 3]])
matrix2 = tf.constant([[2],[2]])
product = tf.matmul(matrix1, matrix2)

sess = tf.Session()
result = sess.run(product)
print result
sess.close()

with tf.Session() as sess:
    result = sess.run(product)
    print result

#创建一个变量
state = tf.Variable(0, name="couter")
#创建一个OP
one = tf.constant(1)
new_value = tf.add(state, one)
update = tf.assign(state, new_value)
#启动图
init_op = tf.global_variables_initializer()
with tf.Session() as sess:
    sess.run(init_op)
    print sess.run(state)
    for _ in range(3):
        sess.run(update)
        print sess.run(state)

input1 = tf.constant(3.0)
input2 = tf.constant(2.0)
input3 = tf.constant(5.0)
intermed = tf.add(input2, input3)
#fetch
with tf.Session() as sess:
  result = sess.run([intermed, input1, input2, input3])
  print result

#feed
input1 = tf.placeholder(tf.float32)
input2 = tf.placeholder(tf.float32)
output = tf.add(input1, input2)

with tf.Session() as sess:
  print sess.run([output], feed_dict={input1:[7.], input2:[2.]})

