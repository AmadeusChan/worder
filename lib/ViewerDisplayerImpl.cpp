#include "ViewerDisplayerImpl.h"
#include "MyException.h"

ViewerDisplayerImpl::ViewerDisplayerImpl(Viewer* start_page) : current_page_(start_page) {}

string ViewerDisplayerImpl::show()
{
	if (warning_infomation == "")
	{
		return current_page_->show();
	}
	else
	{
		return current_page_->show() + "\n[" + warning_infomation + "]\n";
	}
}

void ViewerDisplayerImpl::submit(string command)
{
	try
	{
		warning_infomation = "";
		Viewer* temp = current_page_->submit(command);
		current_page_ = temp == NULL ? StartPage::get_instance() : temp;
	}
	catch (MyException exception)
	{
		warning_infomation = exception.what();
	}
}