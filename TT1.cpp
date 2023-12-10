const int MAXN=1e5+5;
const int INF=INT_MAX;
class TT_node{
	friend class simple_TT;
	private:
		int left,right,v,sz,fr,to;
		TT_node(void){
			left=right=0;
			sz=0;
			fr=to=INF;
		}
		void operator=(TT_node x){
			v=x.v;
			fr=x.fr;
			to=x.to;
		}
};
class simple_TT{
	private:
		int n;
		int root;
		TT_node tr[MAXN];
		int new_node(int v){
			n++;
			tr[n]={0,0,v,1,pre(v),suc(v)};
			return n;
		}
		int new_node(void){
			n++;return n;
		}
		void pushup(int p){
			tr[p].sz=tr[tr[p].left].sz+tr[tr[p].right].sz+1;
		}
	public:
		const int pre(const int v){
			//......
			int p;
			return p;
		}
		const int suc(const int v){
			//.......
			int p;
			return p;
		}
		void ins(int& p=root,const int id,const int v){
			if(p==0){
				p=new_node();
				tr[p]=tr[id];
				if(tr[p].fr) tr[tr[p].fr].to=n;
				if(tr[p].to) tr[tr[p].to].fr=n;
				return;
			}
			if(v<tr[p].v){
				if(tr[tr[p].left].sz>tr[tr[p].right].sz){
					ins(tr[p].right,p,tr[p].v);
					if(tr[p].fr) tr[tr[p].fr].to=n;
					if(tr[p].to) tr[tr[p].to].fr=n;
					int f=tr[p].fr;
					tr[p]=tr[f];
					del(tr[p].left,f,tr[f].v);
					if(tr[p].fr) tr[tr[p].fr].to=p;
					if(tr[p].to) tr[tr[p].to].fr=p;
				}
				ins(tr[p].left,id,v);
			}else{
				if(tr[tr[p].left].sz<tr[tr[p].right].sz){
					ins(tr[p].left,p,tr[p].v);
					if(tr[p].fr) tr[tr[p].fr].to=n;
					if(tr[p].to) tr[tr[p].to].fr=n;
					int f=tr[p].to;
					tr[p]=tr[f];
					del(tr[p].right,f,tr[f].v);
					if(tr[p].fr) tr[tr[p].fr].to=p;
					if(tr[p].to) tr[tr[p].to].fr=p;
				}
				ins(tr[p].left,id,v);
			}
			pushup(p);
		}
};
