import pandas as pd
from mlxtend.preprocessing import TransactionEncoder

def apriori(dataset, min_support, sup_dot):
    # Bước 1: Tạo DataFrame từ tập dữ liệu
    te = TransactionEncoder()
    te_ary = te.fit(dataset).transform(dataset)
    df = pd.DataFrame(te_ary, columns=te.columns_)

    # Bước 2: Tạo tập ứng viên đầu tiên từ các item đơn lẻ
    itemsets = []
    for col in df.columns:
        itemsets.append(frozenset([col]))
        # if df[col].sum() >= sup_dot:
            # itemsets.append(frozenset([col]))

    k = 2
    while itemsets:
        # Bước 3: Tính toán độ hỗ trợ cho các tập ứng viên
        candidate_counts = {}
        for transaction in dataset:
            for itemset in itemsets:
                if itemset.issubset(transaction):
                    if itemset not in candidate_counts:
                        candidate_counts[itemset] = 1
                    else:
                        candidate_counts[itemset] += 1

        # Bước 4: In ra các tập ứng viên phổ biến trước khi loại bỏ chúng
        print(f"Candidate Itemsets (k={k-1}):")
        for itemset in itemsets:
            count = candidate_counts.get(itemset, 0) # Lấy độ hỗ trợ của tập ứng viên
            print(f"Itemset: {itemset}, Sup: {count}, Support: {count / len(dataset)}") # In ra độ hỗ trợ
        print('\n')

        # Bước 5: Lọc các tập ứng viên thỏa mãn ngưỡng hỗ trợ
        print(f"Frequent Itemsets (k={k-1}) with Support >= {min_support}:")
        frequent_itemsets = []
        for itemset, count in candidate_counts.items():
            support = count / len(dataset)
            # print(count ,'/', len(dataset))
            if support >= min_support:
                frequent_itemsets.append((itemset, support))
                print(f"Itemset: {itemset}, Sup: {count}, Support: {count / len(dataset)}") # In ra độ hỗ trợ

        # Bước 6: In ra các tập ứng viên phổ biến
        # print(f"Frequent Itemsets (k={k-1}) with Support >= {min_support}:")
        # for itemset, support in frequent_itemsets:
            # print(f"Itemset: {itemset}, Support: {support}")
        print('\n')

        # Bước 7: Tạo các tập ứng viên k+1 từ các tập ứng viên k
        itemsets = generate_next_candidates([itemset for itemset, support in frequent_itemsets], k)
        k += 1

# def generate_next_candidates(prev_candidates, k):
#     candidates = []
#     n_candidates = len(prev_candidates)
#     for i in range(n_candidates):
#         for j in range(i+1, n_candidates):
#             prev_candidate1 = list(prev_candidates[i])
#             prev_candidate2 = list(prev_candidates[j])
#             prev_candidate1.sort()
#             prev_candidate2.sort()
#             # So sánh k-1 phần tử đầu tiên của 2 tập ứng viên trước
#             if prev_candidate1[:k-2] == prev_candidate2[:k-2]:
#                 new_candidate = set(prev_candidate1).union(prev_candidate2)
#                 candidates.append(frozenset(new_candidate))
#     return candidates
# def generate_next_candidates(prev_candidates, k):
#     candidates = []
#     n_candidates = len(prev_candidates)
#     for i in range(n_candidates):
#         for j in range(i+1, n_candidates):
#             prev_candidate1 = list(prev_candidates[i])
#             prev_candidate2 = list(prev_candidates[j])
#             prev_candidate1.sort()
#             prev_candidate2.sort()
#             new_candidate = set(prev_candidate1).union(prev_candidate2)
#             candidates.append(frozenset(new_candidate))
#     return candidates
def generate_next_candidates(prev_candidates, k):
    candidates = []
    unique_candidates = set()  # Tạo một set để lưu trữ các tập ứng viên duy nhất
    n_candidates = len(prev_candidates)
    for i in range(n_candidates):
        for j in range(i+1, n_candidates):
            prev_candidate1 = list(prev_candidates[i])
            prev_candidate2 = list(prev_candidates[j])
            prev_candidate1.sort()
            prev_candidate2.sort()
            new_candidate = frozenset(set(prev_candidate1).union(prev_candidate2))  # Tạo tập ứng viên mới
            if len(new_candidate) == k:  # Chỉ thêm tập ứng viên có k phần tử
                # Kiểm tra xem tập ứng viên mới đã tồn tại trong danh sách chưa
                if new_candidate not in unique_candidates:
                    candidates.append(new_candidate)
                    unique_candidates.add(new_candidate)  # Thêm tập ứng viên mới vào tập hợp
    return candidates


# Tập dữ liệu giao dịch
# dataset = [
#     ['A', 'B', 'C', 'D', 'E'],
#     ['A', 'B', 'C'],
#     ['D', 'C', 'B'],
#     ['A', 'B', 'D'],
#     ['D', 'C'],
#     ['D', 'C', 'A', 'B'],
#     ['A', 'B', 'E', 'D']
# ]

# min_support = 0.5
# sup_dot = 4

dataset = [
    ['1', '3', '4'],
    ['2', '3', '5'],
    ['1', '2', '3', '5'],
    ['2', '5']
]

min_support = 0.5
sup_dot = 2

# dataset = [
#     ['f','a','c','d','g','i','m','p'],
#     ['a','b','c','f','l','m','o'],
#     ['b','f','h','j','o'],
#     ['b','c','k','s','p'],
#     ['a','f','c','e','l','p','m','n'],
# ]

# min_support = 3/len(dataset)
# sup_dot = 3

apriori(dataset, min_support, sup_dot)