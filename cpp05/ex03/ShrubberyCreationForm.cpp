#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_shrubbery", 145, 137)
{
	_target = "defaut";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
AForm(other._target, other.getGradeSigned(), other.getGradeExec())
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	_target = target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false) {
		throw std::out_of_range(AForm::FormNotSignedException());
	}
	if (executor.getGrade() > this->getGradeExec()) {
		throw std::out_of_range(AForm::GradeTooLowException());
    }
    createFile();
}

void ShrubberyCreationForm::createFile() const
{
	std::ofstream file_target((_target + "_shrubbery").c_str());

	if (!file_target.is_open()) {
		throw std::out_of_range("Form::file dont open or read");
	}
	file_target << "             _{\\ _{\\{\\/}/}/}__                             " << std::endl;
	file_target << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file_target << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file_target << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file_target << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file_target << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file_target << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file_target << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file_target << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file_target << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file_target << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file_target << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file_target << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file_target << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file_target << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file_target << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file_target << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
	file_target << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file_target << "              (_)  \\.-\'.-/" << std::endl;
	file_target << "          __...--- |\'-.-\'| --...__" << std::endl;
	file_target << "    _...--   .-\'   |\'-.-\'|  \' -.  --..__" << std::endl;
	file_target << "  -    \' .  . \'    |.\'-._| \'  . .  \'   jro" << std::endl;
	file_target << " .  \'-  \'    .--\'  | \'-.\'|    .  \'  . \'" << std::endl;
	file_target << "          \' ..     |\'-_.-|" << std::endl;
	file_target << "  .  \'  .       _.-|-._ -|-._  .  \'  ." << std::endl;
	file_target << "              .\'   |\'- .-|   \'." << std::endl;
	file_target << "  ..-\'   \' .  \'.   `-._.-�   .\'  \'  - ." << std::endl;
	file_target << "   .-\' \'        \'-._______.-\'     \'  ." << std::endl;
	file_target << "        .      ~," << std::endl;
	file_target << "    .       .   |\\   .    \' \'-." << std::endl;
	file_target << "    ___________/  \\____________" << std::endl;
	file_target << "   /  Why is it, when you want \\ " << std::endl;
	file_target << "  |  something, it is so damn   |" << std::endl;
	file_target << "  |    much work to get it?     |" << std::endl;
	file_target << "   \\___________________________/" << std::endl;
	file_target.close();
}