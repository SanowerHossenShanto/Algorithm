#include <iostream>#include <queue>#include <unordered_map>#include <string>using namespace std;// Huffman tree nodestruct MinHNode {    unsigned freq;    char data;    MinHNode *left, *right;    MinHNode(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}};// Custom comparator for priority queuestruct compare {    bool operator()(MinHNode* l, MinHNode* r) {        return (l->freq > r->freq);    }};// Function to generate Huffman tree and codesvoid generateCodes(MinHNode* root, string code, unordered_map<char, string>& codes) {    if (root == nullptr)        return;    if (root->data != '$')        codes[root->data] = code;    generateCodes(root->left, code + "0", codes);    generateCodes(root->right, code + "1", codes);}// Function to perform Huffman codingvoid huffmanEncoding(char data[], int freq[], int size) {    // Create min heap using frequency    priority_queue<MinHNode*, vector<MinHNode*>, compare> minHeap;    for (int i = 0; i < size; ++i)        minHeap.push(new MinHNode(data[i], freq[i]));    // Build Huffman tree    while (minHeap.size() != 1) {        MinHNode *left = minHeap.top(); minHeap.pop();        MinHNode *right = minHeap.top(); minHeap.pop();        MinHNode *top = new MinHNode('$', left->freq + right->freq);        top->left = left;        top->right = right;        minHeap.push(top);    }    // Generate Huffman codes    unordered_map<char, string> codes;    generateCodes(minHeap.top(), "", codes);    // Print Huffman codes    cout << "Huffman Codes:\n";    for (auto it : codes)        cout << it.first << " : " << it.second << endl;}int main() {    int n;    cout << "Enter the number of characters: ";    cin >> n;    char data[n];    int freq[n];    cout << "Enter " << n << " characters and their frequencies:\n";    for (int i = 0; i < n; ++i) {        cout << "Character " << i + 1 << ": ";        cin >> data[i];        cout << "Frequency: ";        cin >> freq[i];    }    huffmanEncoding(data, freq, n);    return 0;}