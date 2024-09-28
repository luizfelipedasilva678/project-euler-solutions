import math

numerator_result = 1
denominator_result = 1

for i in range(10, 99):
    for j in range(10, 99):
        if i / j < 1:
            common_term = set(str(i)).intersection(set(str(j)))

            if len(common_term) == 1 and "0" not in common_term:
                numerator_set = set(str(i)).difference(common_term)
                denominator_set = set(str(j)).difference(common_term)

                if (
                    len(numerator_set) == 1
                    and len(denominator_set) == 1
                    and "0" not in denominator_set
                ):
                    numerator = int(numerator_set.pop())
                    denominator = int(denominator_set.pop())
                    result = numerator / denominator

                    if result == (i / i) / (j / i):
                        numerator_result *= numerator
                        denominator_result *= denominator


print(
    f"Answer: {math.trunc(numerator_result/numerator_result)}/{math.trunc(denominator_result/numerator_result)}"
)
