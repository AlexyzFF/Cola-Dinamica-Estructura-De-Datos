#include <iostream>

struct nodo  //Es la estructura del nodo, guarda el dato y la direccion siguiente 
{
	int dato;
	nodo *sig;
}
;

using namespace std;
class ClaseCola
{
	private:
		nodo *frente;
		nodo *final;
		
	
	public:
		ClaseCola();
		void agregar(int);
		void EleFinal();
		void mostrar();
		void sacar();
		bool vacia();
	    ~ClaseCola();	
};

ClaseCola::ClaseCola()
{
	frente=new nodo;
	final=frente;
}

bool ClaseCola::vacia()
{
    if(frente==final)
    {
    	return 1;
	}
	else
	{
		return 0;
	}
}

void ClaseCola::agregar(int elemento)
{
	nodo *temp;
	
	temp=new nodo;
	final->dato=elemento;
	final->sig=temp;
	final=temp;
}

ClaseCola::~ClaseCola()
{
	nodo *t=frente;
	
	while(t!=final)
	{
		t=t->sig;
		delete frente;
		frente=t;
	}
}

void ClaseCola::EleFinal()
{
	nodo *temporal=frente;
	
	if(vacia()==1)
	{
		cout<<"La Cola Esta Vacia\n"<<endl;
	}
	else
	{
		while(temporal!=final)
		{
			if(temporal->sig==final)
			{
				cout<<"El Ultimo Elemento Insertado Es="<<temporal->dato<<endl;
				temporal=temporal->sig;
			}
			else
			{
				temporal=temporal->sig;
			}	
		}
		cout<<"\n";
	}
}

void ClaseCola::sacar()
{
   nodo *tem=frente;
   
   if(vacia()==1)
   {
   	   cout<<"La Cola Esta Vacia\n"<<endl;
   }
   else
   {
       cout<<"El Dato A Sacar Es="<<tem->dato<<"\n"<<endl;
       tem=tem->sig;
       delete frente;
       frente=tem;
   }  
}

void ClaseCola::mostrar()
{
	nodo *te=frente;
	
    if(vacia()==1)
    {
    	cout<<"La Cola Esta Vacia\n"<<endl;
	}
	else
	{
		cout<<"La Cola Se Encuentra De La Siguiente Manera:\n"<<endl;
		
		do
	      {
		    cout<<te->dato<<"|";
		    te=te->sig;
	      }
	while(te!=final);
	
cout<<"\n"<<endl;	    
	}
}

int main(int argc, char** argv)
{
	int opc,num;
	ClaseCola din;
	
	do
	{
	cout<<"Cola Dinamica\n"<<endl;
	
	cout<<"MENU\n"<<endl;
	
    cout<<"1°Agregar Dato"<<endl;
	cout<<"2°Sacar Dato"<<endl;
	cout<<"3°Imprimir Cola Dinamica"<<endl;
	cout<<"4°Imprimir Ultimo Dato Insertado"<<endl;
	cout<<"5°Salir"<<endl;
	
	cout<<"\nElije una opcion"<<endl;
	cin>>opc;
	
	system("cls");
	
	switch(opc)
	{
		case 1:
			{
				cout<<"Inserta El Dato"<<endl;
			    cin>>num;
			
			    din.agregar(num);
			    cout<<"\n";
			    
			    system("pause");
			    break;
			}
		case 2:
		    {
		         din.sacar();
		         
		         system("pause");	
		         break;	
		    }
		case 3:
		    {
		        din.mostrar();
		        
		 	    system("pause");
		 	    break;	 
		    }
	     case 4:
		   {
		 	    din.EleFinal();
		 	    
				system("pause");
				break; 
		    } 
}
system("cls");
}while(opc<5);
	return 0;
}
