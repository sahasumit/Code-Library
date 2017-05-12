


struct Node {
    int nxt[26];
    int endMark;
    Node() {
        for( int i = 0; i < 26; i++ )nxt[i] = 0;
        endMark = 0;
    }
};


const int SIZE_ = 2000;
Node Trie[SIZE_ * ( SIZE_ / 2 ) + 7];
int top = 0;

void insert( string str ) {
    int len = str.size(), cur_inx = 0, id;
    for( int i = 0; i < len; i++ ) {
        id = str[i] - 'a';
        if( Trie[cur_inx].nxt[id] == 0 )
            Trie[cur_inx].nxt[id] = ++top;
        cur_inx = Trie[cur_inx].nxt[id];
    }
    Trie[cur_inx].endMark++;
}

int search( string str ) {
    int len = str.size(), cur_inx = 0, id;
    for( int i = 0; i < len; i++ ) {
        id = str[i] - 'a';
        if( Trie[cur_inx].nxt[id] == 0 )
            return 0;
        cur_inx = Trie[cur_inx].nxt[id];
    }
    return Trie[cur_inx].endMark;
}
void deleted(int cur_index)
{

    for(int i=0; i<26; i++)
        if(Trie[cur_index].nxt[i])
        {
            deleted(Trie[cur_index].nxt[i]);
        }

    for(int i=0; i<26; i++)
        Trie[cur_index].nxt[i]=0,Trie[cur_index].endMark=0;

}
