numbers = list(map(int, input().split()))

size = abs(numbers[1] - numbers[0]) + 1
List = [0] * size

for i in range(size):
    List[i] = numbers[0] + i
    
List2 = list(input().split())
List2 = [int(x) if x.isdigit() else x for x in List2]
# print(List2)
diff = set(List) - set(List2)
diff = list(diff)

fizz = [i for i, value in enumerate(List2) if value == 'Fizz' or value == 'FizzBuzz']
fizz_cnt = sum(1 for value in List2 if value == 'Fizz')
buzz = [i for i, value in enumerate(List2) if value == 'Buzz' or value == 'FizzBuzz']
buzz_cnt = sum(1 for value in List2 if value == 'Buzz')
FizzBuzz = [i for i, value in enumerate(List2) if value == 'FizzBuzz']
FizzBuzz_cnt = sum(1 for value in List2 if value == 'FizzBuzz')


if fizz_cnt == 1:
    if FizzBuzz_cnt == 0:
        a = (List[fizz[0]])
    else:
        a = abs(List[fizz[0]] - List[fizz[1]])
elif fizz_cnt == 0:
    a = (List[FizzBuzz[0]])
else:
    a = abs(List[fizz[0]] - List[fizz[1]])
    
if buzz_cnt == 1:
    if FizzBuzz_cnt == 0:
        b = (List[buzz[0]])
    else:
        a = abs(List[fizz[0]] - List[fizz[1]])
elif buzz_cnt == 0:
    b = (List[FizzBuzz[0]])
else:
    b = abs(List[buzz[0]] - List[buzz[1]])
    
print(str(a) + " " + str(b))
