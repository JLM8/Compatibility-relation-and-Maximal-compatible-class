#include<iostream>
#include"_Matrix.h"
using namespace std;


int main(){
	//���뼯��A�Ĵ�С �������Ϸ��ļ���A
	cout<<"Please input the size of Gather A..."<<endl;
	int size=0;
	cin>>size;
	cout<<"The size of Gather A is "<<size<<"."<<endl;
	int *A = new int[size];
	cout<<endl;
	//�򼯺�A�����Ԫ�� ���жϺϷ���û���ظ����������ظ����
	cout<<"Please input the elements of Gather A..."<<endl;
	bool Gather_legal = true;
	do{
		for(int i=0; i<size; i++)
			cin>>A[i];
		for(int i=0; i<size; i++){
			for(int j=i+1; j<size; j++)
				if(A[i]==A[j]){
					Gather_legal = false;
					break;
				}else
					Gather_legal = true;
			if(Gather_legal == false)
				break;
		}

		if(Gather_legal == false){
			cout<<"Your can't input the same elements in Gather A!"<<endl;
			cout<<"Please re-input  elements..."<<endl;
		}
	}while(Gather_legal == false);
	//��ӡ����A
	cout<<"Gather A is"<<endl;
	for(int i=0; i<size; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	cout<<"----------------------------------------------------------"<<endl;

	int R[20][20] = {0};

	int sizeR=0;
	cout<<"Please input the size of Gather R"<<endl;
	cin >> sizeR;
	//�ֱ�����R��Ԫ�� ���ж��Ƿ�Ϸ� ���Ϸ��������� �������ھ���A*A��
	for(int i=0; i<sizeR; i++){
		int Rx=0,Ry=0;
		cout<<"Please input X Y of Group R "<<i+1<<endl;

		bool Rx_legal = false, Ry_legal = false;
		do{
			cin>>Rx>>Ry;
			for(int j=0; j<size; j++)
				if(A[j]==Rx){
					Rx_legal = true;
					break;
				}else
					Rx_legal = false;
				if(Rx_legal == true)
					for(int j=0; j<size; j++)
						if(A[j]==Ry){
							Ry_legal = true;
							break;
						}else
							Ry_legal = false;
						
						if(Rx_legal == false || Ry_legal == false){
							cout<<"Your XY can't have the element which isn't in Gather A!"<<endl;
							cout<<"Please re-input your X Y of Group R "<<i+1<<endl;
						}
		}while(Rx_legal == false || Ry_legal == false);
		
		int x=0, y=0;
		for(int i=0; i<size; i++){
			if(Rx==A[i])
				x=i;
		}
		for(int i=0; i<size; i++){
			if(Ry == A[i])
				y=i;
		}
		
		R[x][y] = 1;
	}
	cout<<"Matrix is"<<endl;

	//��ӡ����R

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++)
			cout<<R[i][j]<<"\t";
		cout<<endl;
	}


	bool self_converse = true;  //�Է����ж�
	for(int i=0; i<size; i++){
		if(R[i][i] != 1)
			self_converse = false;
	}
	if(self_converse == true)
		cout<<"With";
	else
		cout<<"Without";
	cout<<" self converse"<<endl;

	bool symmetric = true;  //�Գ����ж�
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++){
			if(R[i][j] != R[j][i])
				symmetric =false;
		}
		if(symmetric == true)
			cout<<"With";
		else
			cout<<"Without";
	cout<<" symmetric"<<endl;
	
	
	//�ж��Ƿ������ݹ�ϵ
	if(self_converse && symmetric){
		cout<<"The Matrix have compatibility relation..."<<endl;

		//��ӡ����򻯾���R
		cout<<"The sumplify Matrix is"<<endl;
		for(int i=1; i<size; i++){
			for(int j=0; j<i; j++)
				cout<<R[i][j]<<"\t";
			cout<<endl;
		}

		//������
		_Matrix C(size+1,size+1);
		for(int i=0; i<size; i++){
			C.write(i,0,A[i]);
			C.write(i,size,1);
		}
		C.write(size,size,0);
		
		//��� n=1 ����ֹ
		if(size!=1){
			int i=size-1;
			
			
			//���� A
			int * B = new int [size-1];
			int num = size;

			// i ֵ�Ŀ���
			for(;i>0;i--){

				// A �Ĵ���
				num--;
				int sizeB = 0;
				for(int j=size-1; j>=i; j--){
					if(R[j][i-1] == 1){
						B[j-num] = A[j];
						sizeB++;
					}
				}
				//��ӡA
				cout<<"i : "<<i<<endl;
				cout<<"B : ";
				for(int j=0; j<sizeB; j++)
					cout<<B[j]<<" ";
				cout<<endl;
				

				//�����У�C��
				for(int k=0; k<size+1; k++){
					bool withsame = false;
					for(int j=0; j<sizeB; j++){
						
						for(int t=0; t<C.read(k,size); t++){
							if(C.read(k,t) == B[j]){
								withsame = true;
								break;
							}
						}

						if(withsame == true)
							break;
					}

					//�������ͬ��Ԫ�� �������
					if(withsame == true){
						//Ѱ�Ҵ�СΪ0������
						int line=0;
						for(int j=0; j<size+1; j++)
							if(C.read(j,size) ==0)
								line = j;

						//cout<<"line : "<<line<<endl;
						
						int cur_size = 0;
						//��Xi����
						C.write(line,cur_size,A[i-1]);
						cur_size+=1;
						//�������ͬԪ�� ������ж���
						for(int j=0; j<sizeB; j++){
							for(int t=0; t<C.read(k,size); t++){
								if(C.read(k,t) == B[j]){
									C.write(line,cur_size,B[j]);
									cur_size ++;
								}
							}
						}	
						C.write(line,size,cur_size);
						/*
						cout<<"line : {";
						for(int j=0; j<C.read(line,size); j++)
							cout<<C.read(line,j)<<" ";
						cout<<"}";
						cout<<endl;
						*/
						
						//Ѱ�Ҹ��е����Ӽ�
						for(int e=0; e<size+1; e++){
							int counter = 0;
							for(int t=0; t<C.read(line,size); t++){
								for(int r=0; r<C.read(e,size); r++){
									if(e!=line){
										if(C.read(e,r) == C.read(line,t))
											counter++;
									}
								}
							}
							//�ж��Ǹ��е����Ӽ� ���Ǹ��������Ӽ�
							if(counter == C.read(e,size)){
								C.write(e,size,0);
								//cout<<e<<"-size="<<0<<endl;
							}else if(counter == C.read(line,size))
								C.write(line,size,0);
						}
					}
					//��ӡ���Ц�
					cout<<"�� : ";
					for(int k=0; k<size+1; k++){
						if(C.read(k,size)!=0){
							cout<<"{ ";
							for(int j=0; j<C.read(k,size); j++){
								cout<<C.read(k,j)<<" ";
							}
							cout<<"} ";
						}
					}
					cout<<endl;

				}
			}
			delete B;
		}
		cout<<"The Maximal Compatible Class is"<<endl;
		for(int i=0; i<size+1; i++){
			if(C.read(i,size)!=0){
				cout<<"{ ";
				for(int j=0; j<C.read(i,size); j++){
					cout<<C.read(i,j)<<" ";
				}
				cout<<"} ";
			}
		}
		cout<<endl;


		C.free_matrix();
	}else
		cout<<"The Matrix have NOT compatibility relation!!!"<<endl;
	
	


	
	//delete R;
	delete A;
	system("pause");
	return 0;
}