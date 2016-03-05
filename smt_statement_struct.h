#define ISITERATIONSTAT 0
#define ISFORSTAT 0
#define ISWHILESTAT 1
#define ISDOWHILESTAT 2

#define ISEXPRSTAT 1

#define ISSELECTIONSTAT 2
#define ISIFSTAT 0
#define ISSWITCHSTAT 1

#define ISCOMPOUNDSTAT 2

#define ISCASEOPTIONSTMT 3

#define ISJUMPSTMT 4
#define ISGOTOSTMT 0
#define ISCONTINUESTMT 1
#define ISBREAKSTMT 2
#define ISRETURNSTMT 3



class SMTStatement {
	protected:
		int smt_statement_type;
	public:
		SMTStatement(int statement_type) 
		{
			smt_statement_type = statement_type;
		}
		~SMTExpression() {}
		int get_type(int& statement_type) 
		{ 
			statement_type = smt_statement_type;
			return 1;
		}
		int set_type(int statement_type)
		{
			smt_statement_type = smt_statement_type;
			return 1;
		}
};
			
