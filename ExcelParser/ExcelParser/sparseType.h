#ifndef H_sparseType
#define H_sparseType

template<class Type>
struct snodeType{
	int row, col; 
	Type val;
	snodeType *down, *right;

	snodeType()
	{
		down=right=this;
		row = -1;
		col = -1;
	}
	snodeType(int prow, int pcol, snodeType *pright, snodeType *pdown, Type v=0 )
	{
		row = prow;
		col = pcol;
		val = v;
		right = pright;
		down = pdown;
	}
};

template<class Type>
class sparseType{
private:
	snodeType<Type> *first;
	int nrow, ncol;
public:
	sparseType();
	sparseType(int n, int m);
	~sparseType();
	void insert(int, int, Type);
	void remove(int, int);
	void print();
	const sparseType& add( sparseType<Type>&);
	const sparseType& product(const sparseType<Type>&);
};
template<class Type>
sparseType<Type>::sparseType()
{
	first = NULL;
}
//Cosntructor: inicializa las cabezas de las filas y las columnas
template<class Type>
sparseType<Type>::sparseType(int n, int m)
{
	nrow = n;
	ncol = m;
	first = new snodeType<Type>;
	first->right = new snodeType<Type>(-1,m,first,0);
	first->right->down=first->right;

	for(int i=1; i<m; i++)
	{
		first->right = new snodeType<Type>(-1,m-i,first->right,0);
		first->right->down = first->right;
	}
	first->down = new snodeType<Type>(n,-1,0,first);
	first->down->right = first->down;
	
	for(int i=1;i<n;i++)
	{
		first->down = new snodeType<Type>(n-i,-1,0,first->down);
		first->down->right = first->down;
	}
	
}
template<class Type>
void sparseType<Type>::print()
{
	snodeType<Type> *nodeRow = first->down;

	for(int i = 1; i < nrow+1; i++)
	{
		nodeRow = nodeRow->right;
		for(int j = 1; j < ncol+1; j++) 
		{
			if(nodeRow->row == i && nodeRow->col == j)
			{
				cout<<nodeRow->val<<"  ";
				nodeRow = nodeRow->right;
			}
			else
			{
				cout<<"0"<<"  ";
			}
		}
		cout<<"\n";
		nodeRow = nodeRow->down;
	}
}

template<class Type>
void sparseType<Type>::insert(int oRow, int oCol, Type oVal)
{

	if(oRow > 0 && oRow < (nrow+1) && oCol > 0 && oCol < (ncol+1))
	{
		
		
		snodeType<Type> *nodeRow = first->down, *beforeNodeRow;
		snodeType<Type> *nodeCol = first->right, *beforeNodeCol;
		
		while(nodeRow->row != oRow)	
			nodeRow = nodeRow->down;
		
		
		while(nodeCol->col != oCol)
			nodeCol = nodeCol->right;
		
		beforeNodeRow = nodeRow;
		beforeNodeCol = nodeCol;
		nodeRow = nodeRow->right;
		nodeCol = nodeCol->down;
		
		while(nodeRow->col != -1 && nodeRow->col < oCol)
		{
			
			beforeNodeRow = nodeRow;
			nodeRow = nodeRow->right;
		}

		while(nodeCol->row != -1 && nodeCol->row < oRow)
		{
			beforeNodeCol = nodeCol;
			nodeCol = nodeCol->down;
		}

		if(nodeRow->col != oCol)
		{
			snodeType<Type> *newNode = new snodeType<Type>(oRow, oCol, nodeRow, nodeCol, oVal);
			beforeNodeRow->right = newNode;
			beforeNodeCol->down = newNode;		
		}		
		else
		{
			nodeRow->val = oVal;
		}

	}
	else
	{
		cout<<"La posicion a insertar esta fuera del rango"<<endl;
	}
	
}

template<class Type>
void sparseType<Type>::remove(int oRow, int oCol)
{
	if(oRow > 0 && oRow < (nrow+1) && oCol > 0 && oCol < (ncol+1))
	{
		
		
		snodeType<Type> *nodeRow = first->down, *beforeNodeRow;
		snodeType<Type> *nodeCol = first->right, *beforeNodeCol;
		
		while(nodeRow->row != oRow)	
			nodeRow = nodeRow->down;
		
		
		while(nodeCol->col != oCol)
			nodeCol = nodeCol->right;
		
		beforeNodeRow = nodeRow;
		beforeNodeCol = nodeCol;
		nodeRow = nodeRow->right;
		nodeCol = nodeCol->down;
		
		while(nodeRow->col != -1 && nodeRow->col < oCol)
		{
			beforeNodeRow = nodeRow;
			nodeRow = nodeRow->right;
		}

		while(nodeCol->row != -1 && nodeCol->row < oRow)
		{
			beforeNodeCol = nodeCol;
			nodeCol = nodeCol->down;
		}
		
		if(nodeRow->col == oCol)
		{
			beforeNodeRow->right = nodeRow->right;
			beforeNodeCol->down = nodeCol->down;
			delete nodeCol;
			
		}		
		else
		{
			cout<<"No se encontro el dato para borrar"<<endl;
		}

	}
	else
	{
		cout<<"La posicion a borrar esta fuera del rango"<<endl;
	}
}
template<class Type>
const sparseType<Type>& sparseType<Type>::add( sparseType<Type>& otherMatriz)
{
	if(nrow == otherMatriz.nrow && ncol == otherMatriz.ncol)
	{
		snodeType<Type>* matrizA = first->down;
		snodeType<Type>* matrizB = otherMatriz.first->down;

		this->print();
		cout<<"q sumo "<<first->down->right->val<<endl;
		first=first->down;
		cout<<"q sumo "<<first->down->right->val<<endl;
		first=first->down;
		cout<<"q sumo "<<first->down->right->val<<endl;
		first=first->down;

		cout<<"q sumo "<<otherMatriz.first->down->right->val<<endl;
		otherMatriz.first=otherMatriz.first->down;
		cout<<"q sumo "<<otherMatriz.first->down->right->val<<endl;
		otherMatriz.first=otherMatriz.first->down;
		cout<<"q sumo "<<otherMatriz.first->down->right->val<<endl;
		otherMatriz.first=otherMatriz.first->down;
	

     	//otherMatriz.print();
		sparseType<Type> *newSparse = new sparseType<Type>(nrow, ncol);
		 newSparse->first=newSparse->first->right;
		//newSparse->first=newSparse->first->down;

		for(int i= 0;i<nrow;i++)
		{
			
			//cout<<newSparse->first->down->row<<" ... "<<newSparse->first->down->col<<endl;
			for(int j= 0;j<ncol;j++)
			{
				
				//newSparse->first->down->right->val=matrizA->down->right->val + matrizB->down->right->val;
				//cout<<"valor"<<newSparse->first->down->right->val<<endl;
				//cout<<newSparse->first->down->right->row<<"  "<<newSparse->first->down->right->col<<endl;
				cout<<newSparse->first->down->row<<"  "<<newSparse->first->down->col<<endl;
				newSparse->first=newSparse->first->down->down;
				matrizA=matrizA->down;
				matrizB=matrizB->down;
				//newSparse->first=newSparse->first->right;

			}
			newSparse->first=newSparse->first->right;
		}
		
		return *newSparse;
		
	}
	else
	{
		cout<<"No se puede sumar las matrices"<<endl;
		return *(new sparseType<Type>);
	}
}
template<class Type>
const sparseType<Type>& sparseType<Type>::product(const sparseType<Type>& otherMatriz)
{
	if(ncol == otherMatriz.nrow)
	{
		snodeType<Type>* matrizA = first->down;
		snodeType<Type>* matrizB = otherMatriz.first->down;
		sparseType<Type> *newSparseMatriz = new sparseType<Type>(nrow, ncol);
		return *newSparseMatriz;
		
	}
	else
	{
		cout<<"No se puede multiplicar las matrices"<<endl;
		return *(new sparseType<Type>);
	}
}
template<class Type>
sparseType<Type>::~sparseType()
{

}
#endif
