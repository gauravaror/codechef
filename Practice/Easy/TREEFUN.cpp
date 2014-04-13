//Included files
#include <iostream>
#include <malloc.h>
#include <math.h>
#include <list>
#include <set>


//Section to define for using in code
//#define NOTJUDGE


using namespace std;

// Node to carry structure of Tree.
struct TreeNode {
	int num ;
    int level;
    int processedanc;
    list<int> child;
	TreeNode * Parent ;
};

int doFun(int,set<int>,TreeNode *);
void dfs(int node,TreeNode * vertices,int N,int nr);
int processlca(TreeNode *,int,int,int);

int main() {
	int testcases;
	cin>>testcases;
	for(int i = 0;i < testcases;i++) {
		int treevertice;
		int treequeries;
		cin>>treevertice>>treequeries;
		TreeNode *treevertices = new TreeNode[50000];
		int Ai,Aj;
        int maxlevel = 1;
		#ifdef NOTJUDGE
            cout<<"TreeVertices "<<treevertice<<"  Tree Query  "<<treequeries<<endl;
        #endif
		for (int j = 0;j< treevertice-1;j++) {
			cin>>Ai>>Aj;
			if ( treevertices[Ai].num == 0) {
				treevertices[Ai].num = Ai;
//                treevertices[Ai].level  =  1;
			}
			if (treevertices[Aj].num ==  0) {
				treevertices[Aj].num = Aj;
				treevertices[Aj].Parent = &treevertices[Ai];
                treevertices[Aj].level  = treevertices[Ai].level + 1;
                treevertices[Ai].child.push_back(Aj);
                if ( maxlevel < treevertices[Aj].level) 
                {   
                    maxlevel = treevertices[Aj].level;
                }
			}
		}
		#ifdef NOTJUDGE
		for (int j = 1;j< treevertice+1;j++) {
			if(treevertices[j].Parent != NULL) {
			cout<<"Node Aj = "<<j<<"Parent = "<<treevertices[j].Parent->num<<"Level of the node :"<<treevertices[j].level<<endl;
			}
			else {
			cout<<"Node Aj = "<<j<<"Parent = NOPARENT"<<"Level of the node :"<<treevertices[j].level<<endl;
			}
            cout<<"Childerens of the Node"<<endl;
            list<int>::iterator it;
            for(it = treevertices[j].child.begin();it != treevertices[j].child.end();it++) {
                cout<<"  "<<*it<<endl;
            }
		    }
            cout<<"Max level "<<maxlevel<<endl;
		#endif
       dfs(1,treevertices,treevertice,floor(sqrt(maxlevel)));
		#ifdef NOTJUDGE
		for (int j = 1;j< treevertice+1;j++) {
			if(treevertices[j].Parent != NULL) {
//			cout<<"Node Aj = "<<j<<"Parent = "<<treevertices[j].Parent->num<<"Level of the node :"<<treevertices[j].level<<endl;
            cout<<"processlca for j"<<j<<" is "<<treevertices[j].processedanc<<endl;
			}
			else {
			//cout<<"Node Aj = "<<j<<"Parent = NOPARENT"<<"Level of the node :"<<treevertices[j].level<<endl;
            cout<<"processlca for j"<<j<<" is "<<treevertices[j].processedanc<<endl;
			}
            cout<<"Childerens of the Node"<<endl;
            list<int>::iterator it;
            for(it = treevertices[j].child.begin();it != treevertices[j].child.end();it++) {
              //  cout<<"  "<<*it<<endl;
            }
		    }
           // cout<<"Max level "<<maxlevel<<endl;
          #endif
    
          int numvert;
          set<int> vert;
          int num;
          for ( int i = 0 ; i < treequeries ; i++ )
          {
		    #ifdef NOTJUDGE
                cout<<"Query "<<i<<endl;
            #endif
            cin>>numvert;
            for (int j = 0;j<numvert;j++) {
                cin>>num;
                vert.insert(num);
            }
            int fun;
            if ( numvert != 2) {
            fun = doFun(numvert,vert,treevertices);
            vert.clear();
            }
            else {
                set<int>::iterator it = vert.begin();
                int p = *it;
                it++;
                int q = *(it);
                //  int lca = 1;
                int lca =  processlca(treevertices,p,q,1);
                    fun =  treevertices[p].level + treevertices[q].level - 2*(treevertices[lca].level) - 1 ;
		        #ifdef NOTJUDGE
                    cout<<"p "<<p<<" q "<<q<<" lca "<<lca<<endl;
                #endif
           } 
            
		    #ifdef NOTJUDGE
                cout<<"FUNVALUE "<<fun<<endl;
            #endif
            cout<<fun<<endl;
            vert.clear();
          }

        delete []treevertices;
	}

}


void dfs(int node,TreeNode * treestruct,int N,int nr) {
    if ( treestruct[node].level < nr) {   
        treestruct[node].processedanc = 1;
    }
    else {
        if ( treestruct[node].level % nr == 0) {
            treestruct[node].processedanc = treestruct[node].Parent->num;
        }
        else {
            treestruct[node].processedanc = treestruct[node].Parent->processedanc;
        }
    }
    list<int>::iterator it1;
    for (it1 = treestruct[node].child.begin();it1 != treestruct[node].child.end();it1++) {
        dfs(*it1,treestruct,N,nr);
    }
}

int processlca(TreeNode * vert,int p,int q,int vert2) {
    int x = p;
    int y = q;
	#ifdef NOTJUDGE
        cout<<"x"<<x<<"y"<<y<<endl;
    #endif
    while ( vert[x].processedanc != vert[y].processedanc) {
        if ( vert[x].level > vert[y].level ) {
            x = vert[x].processedanc;
        }
        else {
            y = vert[y].processedanc;
        }
    }
    while ( x != y ) {
        if ( vert[x].level > vert[y].level ) {
            if(vert[x].Parent != NULL )
            x = vert[x].Parent->num;
        }
        else {
            if(vert[y].Parent != NULL )
            y = vert[y].Parent->num;
        }
       }
       if ( vert2 != 1) {
           if ( x == p || x == q) {
                x = -1;
           }
       }
    return x;
}

int doFun(int numvert,set<int> verti,TreeNode * treeverti) {
    set<int> number;
    set<int>::iterator i;
    set<int>::iterator j;
    for ( i = verti.begin();i != verti.end();i++) {
      for (j = i,j++; j != verti.end();j++) {
        if ( treeverti[*i].num > 0 && treeverti[*j].num > 0){
            int x = processlca(treeverti,*i,*j,0);
	        #ifdef NOTJUDGE
 	            cout<<x<<endl;        
            #endif
            if ( x == -1 ) {
                return 0;
            }
            if ( number.find(x) == number.end() ) {
                number.insert(x);
            }
          }
      }
    }

    for (i = verti.begin() ; i != verti.end();i++) {
        if (number.find(*i)!= number.end()) {
            return 0;
        }
    }
    if ( number.size() == 1 ) {
        return 1;
    }
   return doFun(number.size(),number,treeverti);
  //  return 0;
}
