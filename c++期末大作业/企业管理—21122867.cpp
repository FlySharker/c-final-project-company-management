#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<sstream>
using namespace std; 
struct employee{                                                 //员工链表结点 
    int num;
	char name[20];
	char department[20];
	int salary;
	int leader;
	employee *next=NULL;
};
struct things{                                                 //事务链表结点 
    int number;
	char affair[20];
	things *next=NULL;
};
employee *head=NULL;                                            //头指针初始化 
things *heady=NULL;                                             //头指针初始化 
int pause(const char *prompt)                                   //菜单界面优化 
{
	int key;
	cout<<prompt<<flush;
	key=getch();
	cout<<endl;
	return key;
}
int menu()                                                              //总菜单 
{
	cout<<"\n           "<<"企业管理系统"<<endl
	    <<"\n\t1 -- 员工信息（E）"
	    <<"\n\t2 -- 事务信息 (T)"
	    <<"\n\t0 -- 退  出（Q）"<<endl;
	return pause("\t 请选择："); 
}
int menu_employee()                                                      //菜单 ——员工信息 
{
	cout<<"\n\t1 -- 输出员工信息列表（O）"
	    <<"\n\t2 -- 查询员工信息（F）"
	    <<"\n\t3 -- 修改员工信息（M）"
	    <<"\n\t4 -- 增加员工信息（A）"
	    <<"\n\t5 -- 删除员工信息（D）"
	    <<"\n\t6 -- 查找直系领导（L）"
	    <<"\n\t7 -- 员工工资排序（C）"
	    <<"\n\t8 -- 保存员工信息（S）"
	    <<"\n\t9 -- 返回初始菜单（R）"
	    <<"\n\t0 -- 退  出（Q）"<<endl;
	return pause("\t 请选择："); 
}
int menu_things()                                                      //菜单 ——事务信息  
{
	cout<<"\n\t1 -- 输出事务信息列表（O）"
	    <<"\n\t2 -- 查询事务信息（F）"
	    <<"\n\t3 -- 增加事务信息（A）"
	    <<"\n\t4 -- 删除事务信息（D）"
	    <<"\n\t5 -- 返回初始菜单（R）"
	    <<"\n\t0 -- 退  出（Q）"<<endl;
	return pause("\t 请选择："); 
} 
employee *createlist1(){                                          //建立员工链表 
	employee *head=NULL,*p,*q;
	char filename[20];
	cout<<"请输入文件名：";
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
things *createlist2(){                                          //建立事务链表 
	things *heady=NULL,*p,*q;
	char filename[20];
	cout<<"请输入文件名：";
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
int salary_compare(const employee *p1,const employee *p2)                //工资比较 
{
	int result=0;
	result=p1->salary-p2->salary;
	return result;
} 
void employeesalary_sortlist(employee *&head)                                 //工资排序 
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
void show_employee(const employee *node)                                 //单个显示员工结点 
{
	cout<<node->num<<" "
	    <<node->name<<" "
	    <<node->department<<" "
		<<node->salary<<" "
		<<node->leader<<endl; 
}
void show_things(const things *node)                                 //单个显示事务结点 
{
	cout<<node->number<<" "
	    <<node->affair<<endl; 
}
employee *search1(employee *ihead,int num)                        //查找员工结点 
{
	employee *q=ihead;
	while(q!=NULL&&q->num!=num)
	{
		q=q->next;
	}
	return q;
}
things *search2(things *uhead,int number)                        //查找事务结点 
{
	things *q=uhead;
	while(q!=NULL&&q->number!=number)
	{
		q=q->next;
	}
	return q;
}
void employeesearch_node(employee *iihead)                               //最终实现员工查找 
{
	int num;
	char name[20];
	char department[20];
	employee *p;
	cout<<"请输入员工编号，姓名及所在部门：";
	cin>>num>>name>>department;
	p=search1(head,num);
	if(p)
	{
		show_employee(p);
	} 
	else
	{
		cout<<"无此员工信息"<<endl; 
	}
}
void thingssearch_node(things *uuhead)                               //最终实现事务查找 
{
	int number;
	things *p,*q;
	cout<<"请输入事务编号：";
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
		cout<<"无此事务信息"<<endl; 
	}
}
employee *modify1(employee *node)                                   //员工修改主体 
{
	int change,re_salary,re_leader;
	char str[80];
	bool bottle=1;
	if(node==NULL) return node;
	cout<<"原有记录"<<endl;
	show_employee(node);
	cout<<"接下来进行修改操作"<<endl;
	while(bottle)
	{
		cout<<"修改员工姓名请按1，修改所属部门请按2，修改工资请按3,修改直系领导请按4，退出修改请按0"<<endl;
	cin>>change;
	switch(change)
	{
		case 1:cout<<"请输入员工姓名：";
		       cin.sync();
		       cin.getline(str,80);
		       strncpy(node->name,str,sizeof(node->name));
		       cout<<"已成功修改"<<endl<<endl; 
			   break;
	    case 2:cout<<"请输入所属部门：";
		       cin.sync();
		       cin.getline(str,80);
		       strncpy(node->department,str,sizeof(node->department));
		       cout<<"已成功修改"<<endl<<endl; 
			   break; 
	    case 3:cout<<"请输入工资：";
	           cin>>re_salary;
			   node->salary=re_salary;
			   cout<<"已成功修改"<<endl<<endl; 
			   break;
		case 4:cout<<"请输入直系领导：";
	           cin>>re_leader;
			   node->leader=re_leader;
			   cout<<"已成功修改"<<endl<<endl; 
			   break;	   
		case 0:bottle=0;
		       break; 
	 }
}
}
void employeemodify_node(employee *head)                                //员工修改外围 
{
	int num;
	cout<<"请输入员工编号：";
	cin>>num;
	employee *p;
	p=search1(head,num);
	if(p!=NULL)
	{
		modify1(p);
	}
	else
	{
		cout<<"无此员工"<<endl; 
	 } 
}
void employee_displaylist(employee *head)                                //显示员工链表
{
	employee *p=head;
	cout<<"显示员工信息列表\n";
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
void things_displaylist(things *head)                                //显示事务链表
{
	things *p=head;
	cout<<"显示事务信息列表\n";
	while(p!=NULL)
	{
		cout<<p->number<<" "
		    <<p->affair<<endl;
		p=p->next;
	}
}
void employee_deletelist(employee *head)                                 //删除员工链表 
{
	employee *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
void things_deletelist(things *head)                                 //删除事务链表 
{
	things *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
employee *insert1(employee *head)                                   //员工插入 
{
	employee *p,*q=head,*r=head;; 
	p=new employee;
	bool flag=1;
	if(head==NULL)
	{
		head=p;
		cout<<"请输入增加的员工编号: ";
	    cin>>p->num;
	    cout<<"请输入员工姓名，所在部门，工资及直系领导：";
	    cin>>p->name>>p->department>>p->salary>>p->leader; 
	    head->next=NULL;
	}
	else{
	while(flag){
	cout<<"请输入增加的员工编号: ";
	cin>>p->num;
    for(r=head;r!=NULL;r=r->next)
    {
    	if(p->num==r->num)
    	{
    		cout<<"此编号已存在"<<endl; 
    		flag=1;
    		break;
		}
			flag=0;
	}
}
    cout<<"请输入员工姓名，所在部门，工资及直系领导：";
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
things *insert2(things *heady)                                 //事务插入 
{
	things *p,*q=heady;
	p=new things;
	if(heady==NULL)
	{
		heady=p;
		cout<<"请输入增加的事务编号及事务: ";
		cin>>p->number>>p->affair;
		heady->next=NULL; 
	}
	else{
	cout<<"请输入增加的事务编号及事务: ";
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
employee *deletenode1(employee *rehead)                                     //删除员工结点 
{
	int num;
	char name[20]; 
	employee *p,*r=rehead;
	if(rehead==NULL) return rehead;
	employee_displaylist(head);  
	cout<<"请输入要删除的员工的编号及姓名：";
	cin>>num>>name;
	p=search1(head,num);
	if(p==NULL)
	{
		cout<<"无此员工"<<endl;
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
things *deletenode2(things *prehead)                                     //删除事务结点 
{
	int number;
	things *p,*t,*r=prehead;
	if(prehead==NULL) return prehead;
	things_displaylist(heady);  
	cout<<"请输入要删除的事务编号：";
	cin>>number;
dele:
	p=search2(heady,number);
	if(p==NULL)
	{
		cout<<"无此事务"<<endl;
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
void employee_save(const employee *head,const char *filename)               //保存员工文件 
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
void things_save(const things *heady,const char *filename)                //保存事务文件 
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
void leader_relationship(employee *head)                         //管理层级 
{
	int num1,num2;
	employee *p,*q;
	cout<<"请输入要查找直系领导的员工编号："; 
	cin>>num1;
	p=search1(head,num1);
	if(p->leader==0)
	{
		cout<<"公司的大boss："<<p->name<<endl
		    <<"当然没有直系领导啦"<<endl;
		return; 
	}
	num2=p->leader;
	q=search1(head,num2);
	if(q==NULL) cout<<p->name<<"的直系领导是："<<p->leader<<"（此员工不在该文件中）"<<endl; 
	else{
	cout<<p->name<<"的直系领导是："<<q->name<<endl; 
        }
}
int main()                                                            //主函数 
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
		                            if(head==NULL) cout<<"无数据"<<endl;
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'f':employeesearch_node(head);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break; 
		                   case 'm':employeemodify_node(head);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'a':head=insert1(head);
		                            employee_displaylist(head);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'd':head=deletenode1(head);
		                            employee_displaylist(head);
		                            if(head==NULL) cout<<"无数据"<<endl; 
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls");
		                            break;
		                   case 'l':leader_relationship(head);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;
						   case 'c':employeesalary_sortlist(head);
						            employee_displaylist(head);
									cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;	
						   case 's':employee_save(head,"employee_final.txt");
						            cout<<"保存成功"<<endl;
									cout<<"输入任意键以继续"<<endl;
				                    cin>>t1;
		                            system("cls"); 
						            break;
						   case 'r':system("cls"); 
						            goto cai;				 		        
		                   case 'q':employee_deletelist(head); 
		                            cout<<"已成功退出";
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
		             	            if(heady==NULL) cout<<"无数据"<<endl;
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'f':thingssearch_node(heady);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'a':heady=insert2(heady);
		                            things_displaylist(heady);
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
		                   case 'd':heady=deletenode2(heady);
		                            things_displaylist(heady);
		                            if(heady==NULL) cout<<"无数据"<<endl; 
		                            cout<<"输入任意键以继续"<<endl;
				                    cin>>t2;
		                            system("cls");
		                            break;
						   case 's':things_save(heady,"things_final.txt");
						            cout<<"保存成功"<<endl;
									cout<<"输入任意键以继续"<<endl;
				                    cin>>t2;
		                            system("cls"); 
						            break;
						   case 'r':system("cls"); 
						            goto cai;		 		        
		                   case 'q':things_deletelist(heady); 
		                            cout<<"已成功退出";
		                            return 0;
						}
					 }
		    case 'q':cout<<"已成功退出";
		             return 0;
		}
	}
	return 0;
}
