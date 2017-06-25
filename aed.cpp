#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;
int main()
{
   const int tam=10;
   int menu,vaga[tam],i,q=0,vd,a=0;
   float f=0;
   string placa[tam],saida;
   //selecionar opcao
   do{
   cout<<"-------------------------------------------------------------\n";
   cout<<"Menu:\n";
   cout<<"-------------------------------------------------------------\n";
   cout<<"1-Entrada\n2-Saida\n3-Vagas disponiveis\n4-Posicoes das vagas disponiveis\n5-Faturamento atual\n6-Sair\n";
   cout<<"-------------------------------------------------------------\n";
   cout<<"Operacao: ";
   cin>>menu;
   cout<<"-------------------------------------------------------------\n";
   cin.ignore();
   //verificar se a opcao selecionada é valida
   if(menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5&&menu!=6)
	  cout<<"\nOperacao invalida, tente novamente\n\n";
   }while(menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5&&menu!=6);
   cout<<"\n";
   for(i=0;i<10;i++)
   {
	  placa[i]=" ";
	  vaga[i]=10;
   }
   while(menu!=6)
   {
		if(menu==1)
        {
		   if(a==10)
		      cout<<"Estacionamento Lotado\n\n";
		   else
		   {   
		      while(placa[a]!=" ")
		      {
		   	     a++;
		      }
		      //recebe a placa do carro
		      cout<<"Placa (ex:ABC 1234): ";
		      //recebe o string com o espaço
              getline(cin,placa[a]);
              //verifica se o tamanho do string é o desejado
              while(placa[a].size()>8||placa[a].size()<8)
              {
                 cout<<"\nPlaca invalida.\n";
                 cout<<"\nPlaca (ex:ABC 1234): ";
                 getline(cin,placa[a]);
              }
              for(i=0;i<a;i++)
              {
              	 //verifica se a placa já foi inserida anteriormente e se o tamanho é o desejado
				 while(placa[a]==placa[i]||placa[a].size()>8||placa[a].size()<8)
                 {
                    if(placa[a]==placa[i])
                      cout<<"\nPlaca ja existente.\n";
                    else  
					  cout<<"\nPlaca invalida.\n";	
                    cout<<"\nPlaca (ex:ABC 1234): ";
                    getline(cin,placa[a]);
                 }
		      }
		      //acrescenta um carro a quantidade já existente no estacionamento
              q++;
              //coloca o carro em uma vaga aleatória
              srand (time(NULL));
    	      vaga[a]=rand()%10;
    	      for(i=0;i<a;i++)
              {
              	 //coloca o carro em uma nova vaga caso a anterior ja esteja ocupada
				 while(vaga[a]==vaga[i])
                 {
                    srand (time(NULL));
    	            vaga[a]=rand()%10;
                 }
		      }
		      //informa a vaga em que o carro estacionará
		      cout<<"\nPlaca:"<<placa[a]<<"   Vaga: "<<vaga[a]<<"\n\n";
		      //aumenta o índice do vetor em um
			  a++;
	       }
	    }
        if(menu==2)
	    {
	       if(q==0)
		     cout<<"Operacao impossivel, o estacionamento esta vazio.\n\n";
		   else
		   {
		      //recebe a placa do carro que vai sair
			  cout<<"Placa: ";
		      getline(cin,saida);
		      //verifica se a placa foi registrada na entrada
              while(saida!=placa[0]&&saida!=placa[1]&&saida!=placa[2]&&saida!=placa[3]&&saida!=placa[4]&&saida!=placa[5]&&saida!=placa[6]&&saida!=placa[7]&&saida!=placa[8]&&saida!=placa[9])
			  {
				 cout<<"\nEste carro nao esta no estacionamento.\n";
			     //pede uma nova placa se a outra não estiver no estacionamento
				 cout<<"\nPlaca: ";
		         getline(cin,saida);
		      }
		      for(i=0;i<10;i++)
              {
		         if(saida==placa[i])
	             {
		            //diminui um da quantidade de carros presentes no estacionamento
					q--;
					//acrescenta R$5,00  ao faturamento atual do estacionamento
		            f+=5;
		            //a vaga recebe um valor inválido permitindo que seja atribuido um novo valor a ela
		            vaga[i]=10;
		            //a placa recebe um valor inválido permitindo que seja atribuido um novo valor a ela
		            placa[i]=" ";
		            //a recebe i para que o vetor possa receber um novo valor quando for escolhido "entrada"
		            a=i;
		            //mostra qual carro saiu
		            cout<<"\n "<<saida<<" saiu."<<endl;
		         }
	          }
	          cout<<"\n";
	       }
		}
        if(menu==3)
        {
           //subtrai o número de carros da quantidade de vagas do estacionamento
		   vd=tam-q;
    	   cout<<"Vagas disponiveis: "<<vd<<"\n\n";
		   if(vd==10)
		     cout<<"Estacionamento vazio.\n\n";
		   if(vd==0)
		     cout<<"Estacionamento lotado.\n\n";	
        }
        if(menu==4)
        {
	       for(i=0;i<10;i++)
		   {
			  if(vaga[i]>=0&&vaga[i]<10)
			    cout<<"Carro "<<i+1<<":"<<" Vaga "<<vaga[i]<<endl;
              else
				cout<<"Carro "<<i+1<<": vazio"<<endl;
           }
           cout<<"\n";
        }
        if(menu==5)
        {
        	//mostra o faturamento
			cout<<"Faturamento atual: R$ "<<f<<",00\n\n";
        }
        //pede para o usuário mescolher uma nova op��o
        do{
        cout<<"-------------------------------------------------------------\n";	
        cout<<"Menu:\n";
        cout<<"-------------------------------------------------------------\n";
        cout<<"1-Entrada\n2-Saida\n3-Vagas disponiveis\n4-Posicoes das vagas disponiveis\n5-Faturamento atual\n6-Sair\n";
        cout<<"-------------------------------------------------------------\n";
        cout<<"Operacao: ";
		cin>>menu;
		cout<<"-------------------------------------------------------------\n";
		cin.ignore();
		if(menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5&&menu!=6)
		  cout<<"\nOperacao invalida, tente novamente\n\n";
		}while(menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5&&menu!=6);
        cout<<"\n";
   }
   //encerra o programa
   cout<<"-------------------------------------------------------------\n";
   cout<<"Programa encerrado\n";
}
