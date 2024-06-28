#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

string BtoDHelper(vector<vector<int>>& m, int i, int j, int k, int l, int r, int c){
    if(c == 0 || r == 0){
        return "";
    }

    int number = m[i][j];
    bool allSame = true;

    for(int o = i; o <= k && allSame; o++) for(int p = j; p <= l && allSame; p++){
        if(number != m[o][p]){
            allSame = false;
            break;
        }
    }

    if(allSame){
        return to_string(m[i][j]);
    }

    int midRow(i + (k-i)/2), midCol(j + (l-j)/2);

    return "D" + BtoDHelper(m, i, j, midRow, midCol, r/2 + (r%2), c/2 + (c%2))
            + BtoDHelper(m, i, midCol+1, midRow, l, r/2 + (r%2), c/2)
            + BtoDHelper(m, midRow+1, j, k, midCol, r/2, c/2 + (c%2))
            + BtoDHelper(m, midRow+1, midCol+1, k, l, r/2, c/2);

}

void DtoBHelper(string& m, vector<vector<int>>& matrix, int& index, int i, int j, int k, int l, int r, int c){
    if(index >= m.size() || c == 0 || r == 0){
        return;
    }

    if(m[index] == 'D'){
        index++;
        int midRow(i + (k-i)/2), midCol(j + (l-j)/2);

        DtoBHelper(m, matrix, index, i, j, midRow, midCol, r/2 + (r%2), c/2 + (c%2));
        DtoBHelper(m, matrix, index, i, midCol+1, midRow, l, r/2 + (r%2), c/2);
        DtoBHelper(m, matrix, index, midRow+1, j, k, midCol, r/2, c/2 + (c%2));
        DtoBHelper(m, matrix, index, midRow+1, midCol+1, k, l, r/2, c/2);

    }else{
        for(int o = i; o <= k; o++) for(int p = j; p <= l; p++){
            matrix[o][p] = m[index];
        }
        index++;
    }
}

string BtoD(string m, int r, int c){
    vector<vector<int>> matrix(r, vector<int>(c, 0)); int index(0);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = m[index++] - 48;
        }
    }

    return BtoDHelper(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, matrix.size(), matrix[0].size());

}

string DtoB(string m, int r, int c){
    vector<vector<int>> matrix(r, vector<int>(c, 0)); int index(0);

    DtoBHelper(m, matrix, index, 0, 0, r-1, c-1, r, c);

    string result = "";
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            result += matrix[i][j];
        }
    }

    return result;
}

int main(){
    string instruction;
    cin>>instruction;
    
    while(instruction != "#"){
        int r, c;
        string incoding, line;
        cin>>r>>c>>line;

        while(line != "D" && line != "B" && line != "#"){
            incoding += line;
            cin>>line;
        }

        string ans = "";

        if(instruction == "B"){
            cout<<"D"<<setw(4)<<right<<r<<setw(4)<<right<<c<<endl;
            
            ans = BtoD(incoding, r, c);

        }else if(instruction == "D"){
            cout<<"B"<<setw(4)<<right<<r<<setw(4)<<right<<c<<endl;
            ans = DtoB(incoding, r, c);
        }

        int i;

        for(i = 0; i < ans.size(); i++){
            cout<<ans[i];

            if(i % 50 == 49){
                cout<<endl;
            }
        }

        if(i % 50 != 0){
            cout<<endl;
        }

        instruction = line;
    }
}