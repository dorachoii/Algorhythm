using namespace std;

int main(){

    // 공백 분리할 문자열 선언
    string input = "abc def ghi";

    // 문자열을 스트림화
    stringstream ss(input);

    // 공백 분리 결과를 저장할 배열
    vector<string> words;

    string word;
    // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
    while (getline(ss, word, ' ')){
        words.push_back(word);
    }

    for(int i = 0; i < words.size(); i++){
        cout << words[i] << endl;
    }
}