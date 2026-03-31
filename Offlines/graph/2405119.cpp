#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

const int MAX = 100;

int ad[MAX][MAX];
bool visited[MAX];
int c;


void dfs(int node, int gr[] , int &size){
    visited[node] = true;
    gr[size++] = node;

    for(int i=0; i<c; i++){
        if(ad[node][i] && !visited[i])
        dfs(i , gr , size);
    }
}


int main(){

    ifstream fin("in.txt");

if(!fin) {
        cout << "File not found\n";
        return 0;
    }
     int match;
    fin >> c >> match;


    for(int i=0; i<c; i++){
        for(int j=0; j<c; j++){
            ad[i][j] = 0;
        }
    }
    for(int i=0; i<c; i++){
        visited[i] = false;
    }

    
    for(int i=0; i<match; i++){
        int a, b;
        fin >> a >> b;
        ad[a][b] = ad[b][a] = 1;
    }

    fin.close();

    int grCount = 0;
    for(int i=0; i<c; i++){
        if(!visited[i]){
            int gr[MAX];
             int size = 0;
            dfs(i, gr, size);

            grCount++;
            cout << "Group " << grCount << ": {";
            for(int j=0; j<size; j++){
                cout << gr[j];
                if(j < size-1) cout << ",";
            }
            cout << "} | ";

bool found = false;
            for(int i = 0; i < size; i++) {
                for(int j = i + 1; j < size; j++) {
                    int a  = gr[i];
                    int b  = gr[j];
                    if(ad[a][b] == 0) {
                        if(found) cout << ", ";
                        cout << "[" << a << "," << b << "]";
                        found = true;
                    }
                }
            }

            if(found == false)
                cout << "none";

            cout << endl;
        }
    }

    cout << grCount << endl;
    return 0;
}