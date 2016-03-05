#define ISVAL 0
#define ISVAR 1
#define ISFUNCTION 2
#define ISOPERATOR 3
#define ISARRAYREF 4
#define ISPTR = 5;
#define ISNULL = 6;
#define ISUNKNOWN = 7;
#define ISASSIGNMENT = 8;

class SMTExpression {
	protected:
		// see defines above
		int smt_expression_type;

	public:
		SMTExpression(int exp_type) 
		{ 
			smt_expression_type = exp_type;
		}
		//SMTExpression(const SMTExpression &obj) 
		//{ 
		//	smt_expression_type = obj.smt_expression_type;
		//}
		~SMTExpression() {}
		int get_type() { return smt_expression_type; }
	
};			
	
class SMTValueExpression : SMTExpression 
{
	private:
		std::string type;
		std::string value;	
		bool is_signed;	
		// limit_high and limit_low are not yet used in set and get
		// this may require more time than is reasonable, so
		// performance tests are necessary, and if it is
		// implemented we will set is_limited to false
		std::string limit_high;
		std::string limit_low;
		bool is_limited;
	public:
		SMTValueExpression() 
		{ 
			smt_expression_type = ISVAL; 
			is_limited = false; 
		}
		// at present SMTValueExpression has no immediate reason
		// to have a copy constructor because all current values
		// are literals and will be copied directly
		//SMTValueExpression(const SMTValueExpression &obj) {}
		int set_type(std::string new_type) 
		{ 
			type = new_type;
			return 1;
		}	
		int get_type(std::string& my_type) 
		{ 
			if (type != "") 
			{ 
				my_type = type;
				return 1; 
			}
			return 0; 
		}
		int set_value(std::string new_value)
		{
			value = new_value; 
			return 1; 
		}
		int get_value(std::string& my_value)
		{
			if (value != "") 
			{ 
				my_value = value; return 1;
			} 
			return 0; 
		}
		// is_limited is set to false by the constructor so
		// it should never be lacking a value, so for now
		// there is no error check for that
		int set_limited(bool new_limited) 
		{ 
			limited = new_limited; 
			return 1; 
		}
		int get_limited(bool& my_limited) 
		{ 
			my_limited = limited;
			return 1; 
		}
		int set_signed(bool my_signed) 
		{ 
			is_signed = my_signed; 
			return 1; 
		}
		int get_signed(bool& my_signed) 
		{ 
			my_signed = is_signed; 
			return 1;
		}
};

	
class SMTVariableExpression : SMTExpression 
{
	private:
		bool assigned;
		std::string base_name;
		std::string full_name;
		SMTExpression* assigned_expression;
	public:
	
		SMTVariableExpression() 
		{ 
			assigned = false; 
			base_name = ""; 
			full_name = ""; 
			assignedExpression = NULL;
		}
		SMTVariableExpression(std::string init_base_name) {
			assigned = false;
			base_name = init_base_name;
			full_name = "";
			assignedExpression = NULL;
		}
		SMTVariableExpression(const SMTVariableExpression& obj)
		{
			assigned_expression = new SMTExpression();
			*assigned_expression = *obj.assigned_expression;
		}
                SMTVariableExpression(std::string init_base_name, std::string init_full_name) 
                {       
                        assigned = false;
                        base_name = init_base_name;
                        full_name = init_full_name;
                        assigned_expression = NULL;
                }

		SMTVariableExpression(std::string init_base_name, std::string init_full_name, SMTExpression* init_assigned_expression) 
		{ 
			assigned = true;
			assigned_expression = new SMTExpression();
			 
			assigned_expression = init_assigned_expression; 
			base_name = init_full_name; 
			full_name = init_base_name;
		}
};

 	//bool assigned;
	int SMTVariableExpression::get_assigned(bool& my_assigned)
	{
		my_assigned = assigned;
		return 1;
	}
	int SMTVariableExpression::set_assigned(bool new_assigned)
	{
		assigned = new_assigned;
		return 1;
	}

        //std::string base_name;
        int SMTVariableExpression::get_base_name(std::string& my_base_name)
	{
		if (base_name == "") 
		{
			return 0;
		}
		my_base_name = base_name;
		return 1;
	}
	int SMTVariableExpression::set_base_name(std::string new_base_name)
	{
		if (new_base_name == "") 
		{
			return 0;
		}
		base_name = new_base_name;
		return 1;
	}
	
	//std::string full_name;
	int SMTVariableExpression::get_full_name(std::string& my_full_name)
	{
		if (full_name == "") 
		{
			return 0;
		}
		my_full_name = full_name;
		return 1;
	}
	int SMTVariableExpression::set_full_name(std::string new_full_name)
	{
		if (new_full_name == "") 
		{
			return 0;
		}
		full_name = new_full_name;
		return 1;
	}
 	
        //SMTExpression* assigned_expression;
        int SMTVariableExpression::get_assigned_expression(SMTExpression*& my_assigned_expression) 
	{
		if (assigned_expression == NULL) 
		{
			return 0;
		}
		my_assigned_expression = assigned_expression;
		return 1;
	}
	int SMTVariableExpression::set_assigned_expression(SMTExpression*& new_assigned_expression)
	{
		if (new_assigned_expression == NULL) 
		{
			return 0;
		}
		assigned_expression = new_assigned_expression;
		return 1;
	}

