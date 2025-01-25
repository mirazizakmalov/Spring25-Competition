num_cases = 1

while(num_cases != 0):
    num_cases = int(input())
    
    if num_cases == 0:
        break
    # print(num_cases)
    List = [0] * 49
    
    for j in range(num_cases):
        numbers = list(map(int, input().split()))
        for ans in numbers[:6]:
            List[ans-1] = 1
            
    # print("Current List:", List)
        
        
    if all(value == 1 for value in List[:49]):
        print("Yes")
    else:
        print("No")