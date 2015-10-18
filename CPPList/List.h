
/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class ListNode
{
public:
    ListNode():value(0),next(this){
    };
	int &data();
	const int data() const; 

private:
    int value;
    ListNode *next;
	friend class CPPList; 

}; // class ListNode�ඨ�����.


/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class CPPList
{
public:
	// CPPList�๹�캯��.
    CPPList():ListHead(),ListEnd(),ListSize(0){
    };

	// CPPList����������
	~CPPList(); 

	// CPPList��ӿ�.
public:
	// �б��Ƿ�Ϊ��
	bool is_empty(); 

	// �б�Ԫ�ظ���
	int size(); 

	// ����list��Ч�ڵ����ʼλ��begin����ֹλ��end
	// ��Щ�ڵ�Ӧ��begin��ʼ����end������������������end����
	// ��˵�listΪ��ʱ������ֵӦ����begin==end
	ListNode *begin(); 
	ListNode *end(); 
	const ListNode *begin() const; 
	const ListNode *end() const; 

	// ����current��ȡ��һ���ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч��ֱ�ӷ���NULL
	ListNode *next(const ListNode *current); 
	const ListNode *next(const ListNode *current) const; 
	
	// β��׷������
	void append(int number);
#if 0
	// ��current֮ǰ��Զ���ݣ�Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void insert(ListNode *current, int); 

	// ɾ��current��ǰ�ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void remove(ListNode *current); 

	// �������
	void clear(); 

    // CPPList��˽���ͳ�Ա����.
#endif
private:
    ListNode * ListHead;
    ListNode * ListEnd;
    int ListSize;

};  // class CPPList�ඨ�����.

