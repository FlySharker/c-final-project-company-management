#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<sstream>
using namespace std; 
struct employee{                                                 //Ա�������� 
    int num;
	char name[20];
	char department[20];
	int salary;
	int leader;
	employee *next=NULL;
};
struct things{                                                 //���������� 
    int number;
	char affair[20];
	things *next=NULL;
};
employee *head=NULL;                                            //ͷָ���ʼ�� 
things *heady=NULL;                                             //ͷָ���ʼ�� 
int pause(const char *prompt)                                   //�˵������Ż� 
{
	int key;
	cout<<prompt<<flush;
	key=getch();
	cout<<endl;
	return key;
}
int menu()                                                              //�ܲ˵� 
{
	cout<<"\n           "<<"��ҵ����ϵͳ"<<endl
	    <<"\n\t1 -- Ա����Ϣ��E��"
	    <<"\n\t2 -- ������Ϣ (T)"
	    <<"\n\t0 -- ��  ����Q��"<<endl;
	return pause("\t ��ѡ��"); 
}
int menu_employee()                                                      //�˵� ����Ա����Ϣ 
{
	cout<<"\n\t1 -- ���Ա����Ϣ�б�O��"
	    <<"\n\t2 -- ��ѯԱ����Ϣ��F��"
	    <<"\n\t3 -- �޸�Ա����Ϣ��M��"
	    <<"\n\t4 -- ����Ա����Ϣ��A��"
	    <<"\n\t5 -- ɾ��Ա����Ϣ��D��"
	    <<"\n\t6 -- ����ֱϵ�쵼��L��"
	    <<"\n\t7 -- Ա����������C��"
	    <<"\n\t8 -- ����Ա����Ϣ��S��"
	    <<"\n\t9 -- ���س�ʼ�˵���R��"
	    <<"\n\t0 -- ��  ����Q��"<<endl;
	return pause("\t ��ѡ��"); 
}
int menu_things()                                                      //�˵� ����������Ϣ  
{
	cout<<"\n\t1 -- ���������Ϣ�б�O��"
	    <<"\n\t2 -- ��ѯ������Ϣ��F��"
	    <<"\n\t3 -- ����������Ϣ��A��"
	    <<"\n\t4 -- ɾ��������Ϣ��D��"
	    <<"\n\t5 -- ���س�ʼ�˵���R��"
	    <<"\n\t0 -- ��  ����Q��"<<endl;
	return pause("\t ��ѡ��"); 
} 
employee *createlist1(){                                          //����Ա������ 
	employee *head=NULL,*p,*q;
	char filename[20];
	cout<<"�������ļ�����";
	cin>>filename;
	ifstream ifile(filename);
	char a[10000];
	while(ifile.getline(a,10000)){
	istringstream b(a);	
	p=new employee;
    b>>p->num>>p->name>>p->department>>p->salary>>p->leader; 
	if(head==NULL) head=p;
	else q->next=p;
	q=p;
}
    ifile.close(); 
	if(head!=NULL) q->next=NULL;
	return head;
}
things *createlist2(){                                          //������������ 
	things *heady=NULL,*p,*q;
	char filename[20];
	cout<<"�������ļ�����";
	cin>>filename;
	ifstream ifile(filename);
	char c[10000];
	while(ifile.getline(c,10000)){
	istringstream d(c);	
	p=new things;
    d>>p->number>>p->affair; 
	if(heady==NULL) heady=p;
	else q->next=p;
	q=p; 
}
	if(heady!=NULL) q->next=NULL;
	return heady;
}
int salary_compare(const employee *p1,const employee *p2)                //���ʱȽ� 
{
	int result=0;
	result=p1->salary-p2->salary;
	return result;
} 
void employeesalary_sortlist(employee *&head)                                 //�������� 
{
	if(head==NULL) return;
	employee *oldlink=head->next;
	head->next=NULL;
	employee *p,*pguard;
	while(oldlink!=NULL)
	{
		p=oldlink;
		oldlink=oldlink->next;
		if(salary_compare(p,head)<0)
		{
			p->next=head;
			head=p;
			continue;
		}
		pguard=head;
		while(pguard->next&&salary_compare(pguard->next,p)<0)
		     pguard=pguard->next;
		p->next=pguard->next;
		pguard->next=p;
	}
}
void show_employee(const employee *node)                                 //������ʾԱ����� 
{
	cout<<node->num<<" "
	    <<node->name<<" "
	    <<node->department<<" "
		<<node->salary<<" "
		<<node->leader<<endl; 
}
void show_things(const things *node)                                 //������ʾ������ 
{
	cout<<node->number<<" "
	    <<node->affair<<endl; 
}
employee *search1(employee *ihead,int num)                        //����Ա����� 
{
	employee *q=ihead;
	while(q!=NULL&&q->num!=num)
	{
		q=q->next;
	}
	return q;
}
things *search2(things *uhead,int number)                        //���������� 
{
	things *q=uhead;
	while(q!=NULL&&q->number!=number)
	{
		q=q->next;
	}
	return q;
}
void employeesearch_node(employee *iihead)                               //����ʵ��Ա������ 
{
	int num;
	char name[20];
	char department[20];
	employee *p;
	cout<<"������Ա����ţ����������ڲ��ţ�";
	cin>>num>>name>>department;
	p=search1(head,num);
	if(p)
	{
		show_employee(p);
	} 
	else
	{
		cout<<"�޴�Ա����Ϣ"<<endl; 
	}
}
void thingssearch_node(things *uuhead)                               //����ʵ��������� 
{
	int number;
	things *p,*q;
	cout<<"�����������ţ�";
	cin>>number;
	q=search2(heady,number);
	for(p=uuhead;p!=NULL;p=p->next)
	{
		if(p->number==number)
		{
			show_things(p);
		}
	}
	if(q==NULL)
	{
		cout<<"�޴�������Ϣ"<<endl; 
	}
}
employee *modify1(employee *node)                                   //Ա���޸����� 
{
	int change,re_salary,re_leader;
	char str[80];
	bool bottle=1;
	if(node==NULL) return node;
	cout<<"ԭ�м�¼"<<endl;
	show_employee(node);
	cout<<"�����������޸Ĳ���"<<endl;
	while(bottle)
	{
		cout<<"�޸�Ա�������밴1���޸����������밴2���޸Ĺ����밴3,�޸�ֱϵ�쵼�밴4���˳��޸��밴0"<<endl;
	cin>>change;
	switch(change)
	{
		case 1:cout<<"������Ա��������";
		       cin.sync();
		       cin.getline(str,80);
		       strncpy(node->name,str,sizeof(node->name));
		       cout<<"�ѳɹ��޸�"<<endl<<endl; 
			   break;
	    case 2:cout<<"�������������ţ�";
		       cin.sync();
		       cin.getline(str,80);
		       strncpy(node->department,str,sizeof(node->department));
		       cout<<"�ѳɹ��޸�"<<endl<<endl; 
			   break; 
	    case 3:cout<<"�����빤�ʣ�";
	           cin>>re_salary;
			   node->salary=re_salary;
			   cout<<"�ѳɹ��޸�"<<endl<<endl; 
			   break;
		case 4:cout<<"������ֱϵ�쵼��";
	           cin>>re_leader;
			   node->leader=re_leader;
			   cout<<"�ѳɹ��޸�"<<endl<<endl; 
			   break;	   
		case 0:bottle=0;
		       break; 
	 }
}
}
void employeemodify_node(employee *head)                                //Ա���޸���Χ 
{
	int num;
	cout<<"������Ա����ţ�";
	cin>>num;
	employee *p;
	p=search1(head,num);
	if(p!=NULL)
	{
		modify1(p);
	}
	else
	{
		cout<<"�޴�Ա��"<<endl; 
	 } 
}
void employee_displaylist(employee *head)                                //��ʾԱ������
{
	employee *p=head;
	cout<<"��ʾԱ����Ϣ�б�\n";
	while(p!=NULL)
	{
		cout<<p->num<<" "
		    <<p->name<<" "
		    <<p->department<<" "
		    <<p->salary<<" "
			<<p->leader<<endl;
		p=p->next;
	}
}
void things_displaylist(things *head)                                //��ʾ��������
{
	things *p=head;
	cout<<"��ʾ������Ϣ�б�\n";
	while(p!=NULL)
	{
		cout<<p->number<<" "
		    <<p->affair<<endl;
		p=p->next;
	}
}
void employee_deletelist(employee *head)                                 //ɾ��Ա������ 
{
	employee *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
void things_deletelist(things *head)                                 //ɾ���������� 
{
	things *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
employee *insert1(employee *head)                                   //Ա������ 
{
	employee *p,*q=head,*r=head;; 
	p=new employee;
	bool flag=1;
	if(head==NULL)
	{
		head=p;
		cout<<"���������ӵ�Ա�����: ";
	    cin>>p->num;
	    cout<<"������Ա�����������ڲ��ţ����ʼ�ֱϵ�쵼��";
	    cin>>p->name>>p->department>>p->salary>>p->leader; 
	    head->next=NULL;
	}
	else{
	while(flag){
	cout<<"���������ӵ�Ա�����: ";
	cin>>p->num;
    for(r=head;r!=NULL;r=r->next)
    {
    	if(p->num==r->num)
    	{
    		cout<<"�˱���Ѵ���"<<endl; 
    		flag=1;
    		break;
		}
			flag=0;
	}
}
    cout<<"������Ա�����������ڲ��ţ����ʼ�ֱϵ�쵼��";
	cin>>p->name>>p->department>>p->salary>>p->leader; 
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	q->next->next=NULL;
}
return head;
}
things *insert2(things *heady)                                 //������� 
{
	things *p,*q=heady;
	p=new things;
	if(heady==NULL)
	{
		heady=p;
		cout<<"���������ӵ������ż�����: ";
		cin>>p->number>>p->affair;
		heady->next=NULL; 
	}
	else{
	cout<<"���������ӵ������ż�����: ";
	cin>>p->number>>p->affair; 
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	q->next->next=NULL;
}
return heady;
}
employee *deletenode1(employee *rehead)                                     //ɾ��Ա����� 
{
	int num;
	char name[20]; 
	employee *p,*r=rehead;
	if(rehead==NULL) return rehead;
	employee_displaylist(head);  
	cout<<"������Ҫɾ����Ա���ı�ż�������";
	cin>>num>>name;
	p=search1(head,num);
	if(p==NULL)
	{
		cout<<"�޴�Ա��"<<endl;
		return rehead; 
	}
	if(rehead->num==num)
	{
		rehead=rehead->next;
		delete p;
	}
	while(r->next!=NULL&&r->next->num!=num)
	{
		r=r->next;
	}
	if(r->next!=NULL)
	{
		r->next=p->next;
		delete p;
    }
    return rehead;
}
things *deletenode2(things *prehead)                                     //ɾ�������� 
{
	int number;
	things *p,*t,*r=prehead;
	if(prehead==NULL) return prehead;
	things_displaylist(heady);  
	cout<<"������Ҫɾ���������ţ�";
	cin>>number;
dele:
	p=search2(heady,number);
	if(p==NULL)
	{
		cout<<"�޴�����"<<endl;
		return prehead; 
	}
	if(prehead->number==number)
	{
		prehead=prehead->next;
		delete p;
		return prehead;
	}
	while(r->next!=NULL&&r->next->number!=number)
	{
		r=r->next;
	}
	if(r->next!=NULL)
	{
		r->next=p->next;
		delete p;
    }
    p=search2(heady,number);
	if(p!=NULL) goto dele; 
    return prehead;
}
void employee_save(const employee *head,const char *filename)               //����Ա���ļ� 
{
	ofstream outfile(filename);
	const employee *p;
	for(p=head;p;p=p->next)
	{
		outfile<<p->num<<" "
		       <<p->name<<" "
		       <<p->department<<" "
		       <<p->salary<<" "
		       <<p->leader<<endl;       
	}
	outfile.close();
}
void things_save(const things *heady,const char *filename)                //���������ļ� 
{
	ofstream outfile(filename);
	const things *p;
	for(p=heady;p;p=p->next)
	{
		outfile<<p->number<<" "
		       <<p->affair<<endl;       
	}
	outfile.close();
}
void leader_relationship(employee *head)                         //����㼶 
{
	int num1,num2;
	employee *p,*q;
	cout<<"������Ҫ����ֱϵ�쵼��Ա����ţ�"; 
	cin>>num1;
	p=search1(head,num1);
	if(p->leader==0)
	{
		cout<<"��˾�Ĵ�boss��"<<p->name<<endl
		    <<"��Ȼû��ֱϵ�쵼��"<<endl;
		return; 
	}
	num2=p->leader;
	q=search1(head,num2);
	if(q==NULL) cout<<p->name<<"��ֱϵ�쵼�ǣ�"<<p->leader<<"����Ա�����ڸ��ļ��У�"<<endl; 
	else{
	cout<<p->name<<"��ֱϵ�쵼�ǣ�"<<q->name<<endl; 
        }
}
int main()                                                            //������ 
{
	system("color F0");
	int choice=1,choice1=1,choice2=1,choice3=0,t1,t2;
	while(choice)
	{
		cai:
		choice=menu();
		system("cls");
		switch(choice)
		{
			case 'e':head=createlist1();
			         system("cls");	
			            while(choice1)
                       {
	                     choice1=menu_employee();                                                    
	                     switch(choice1)
	                     {
		                   case 'o':employee_displaylist(head);
		                            if(head==NULL) cout<<"������"<<endl;
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'f':employeesearch_node(head);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break; 
		                   case 'm':employeemodify_node(head);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'a':head=insert1(head);
		                            employee_displaylist(head);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'd':head=deletenode1(head);
		                            employee_displaylist(head);
		                            if(head==NULL) cout<<"������"<<endl; 
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'l':leader_relationship(head);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;
						   case 'c':employeesalary_sortlist(head);
						            employee_displaylist(head);
									cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;	
						   case 's':employee_save(head,"employee_final.txt");
						            cout<<"����ɹ�"<<endl;
									cout<<"����������Լ���"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;
						   case 'r':system("cls"); 
						            goto cai;				 		        
		                   case 'q':employee_deletelist(head); 
		                            cout<<"�ѳɹ��˳�";
		                            return 0;
	                      }
                       }
		    case 't':heady=createlist2();
		             system("cls"); 
			         while(choice2)
		             {
		             	choice2=menu_things();
		             	switch(choice2)
		             	{
		             	   case 'o':things_displaylist(heady);
		             	            if(heady==NULL) cout<<"������"<<endl;
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'f':thingssearch_node(heady);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'a':heady=insert2(heady);
		                            things_displaylist(heady);
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'd':heady=deletenode2(heady);
		                            things_displaylist(heady);
		                            if(heady==NULL) cout<<"������"<<endl; 
		                            cout<<"����������Լ���"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
						   case 's':things_save(heady,"things_final.txt");
						            cout<<"����ɹ�"<<endl;
									cout<<"����������Լ���"<<endl;
				                    cin>>t2;
		                            system("cls"); 
						            break;
						   case 'r':system("cls"); 
						            goto cai;		 		        
		                   case 'q':things_deletelist(heady); 
		                            cout<<"�ѳɹ��˳�";
		                            return 0;
						}
					 }
		    case 'q':cout<<"�ѳɹ��˳�";
		             return 0;
		}
	}
	return 0;
}
