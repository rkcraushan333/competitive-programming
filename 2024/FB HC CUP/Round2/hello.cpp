
int FindMaximum(int N, vector<vector<int>> edges, vector<int> A, int K) {
    long kLong = K;
    vector<long> change(N); // Direct initialization without assigning 0
    
    long ans = 0;
    
    // Combine calculation of change[i] and summing up A[i] in a single loop
    for (int i = 0; i < N; ++i) {
        long originalValue = static_cast<long>(A[i]);
        long xorValue = originalValue ^ kLong;
        change[i] = xorValue - originalValue;
        ans += originalValue;
    }

    // Using reverse iterators to avoid manual reverse iteration
    sort(change.rbegin(), change.rend());

    // Iterate over the sorted changes and take pairs
    for (int i = 1; i < N; i += 2) {
        long pairSum = change[i] + change[i - 1];
        if (pairSum > 0) {
            ans += pairSum;
        } else {
            break;
        }
    }

    return ans;
}
