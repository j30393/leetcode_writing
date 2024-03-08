k , n = input().split()
layer_num = 0
remaining_num = 0
end_node = 0
start_node = 0
n_k = int(n) - int(k)
for i in range(64,0,-1): 
    if((2 ** (i-1)) - 1 < int(n)):
        layer_num = i
        remaining_num = int(n) - (2 ** (i-1) - 1) #最底下一層的數量
        break

if(k <= 64):
    if(k ** 2 >= n):
        end_node = n
    else:
        end_node = k ** 2 - 1
else:
    end_node = n

# 先把它變成full tree
if(k <= n/2):
    print(end_node - 1 + 1) # first node for the second layer
else:
    temp_num = k - remaining_num
    



print(layer_num, remaining_num)

