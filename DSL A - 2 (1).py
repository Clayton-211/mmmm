def avgScore(mark):
   
    Total = 0
    count = 0
    for i in mark:
        Total = Total + i
        count = count + 1
    return Total / count


def maxScore(mark):   
    max_val = mark[0]
    for m in mark:
        if m > max_val:
            max_val = m
    return max_val


def minScore(mark): 
    min_val = mark[0]
    for i in mark:
        if i < min_val:
            min_val = i
    return min_val


def countAbsent(mark):
    count = 0
    for i in mark:
        if i == 0:
            count = count + 1
    return count


def freqMax(mark):
    max_freq = 0
    element = maxScore(mark)
    for i in mark:
        freq = 0
        for j in mark:
            if i == j:
                freq = freq + 1
        if freq > max_freq:
            max_freq = freq
            element = i
    res = [max_freq, element]
    return res


# Main
N = 5  
print("Note: If a student is absent, add marks = 0")
Marks = [85, 90, 75, 60, 0] 
average = avgScore(Marks)
print("Average Score of the class:", average)

highest = maxScore(Marks)
print("Highest Score in the class:", highest)

lowest = minScore(Marks)
print("Lowest Score in the class:", lowest)

absent_count = countAbsent(Marks)
print("Number of students absent:", absent_count)

frequency_result = freqMax(Marks)
print("Mark with the highest frequency:", frequency_result[1])