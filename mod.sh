echo "10,2" > mem

# after some failed atempts
# echo "0<1<:1+25*5+?0<1<-0>045*8+-g0<p" > p
# echo "0<1<:1+9?0<1<-0>0c0<p" > p

echo "0<0<1</1<*-p" > p
python hackvm.py --init mem p
