#include "pch.h"
#include "MyUserControl.xaml.h"
#if __has_include("MyUserControl.g.cpp")
#include "MyUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::SharedComponent::implementation
{

    void MyUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        RecordOnRendered();
		myButton().Content(box_value(L"Clicked"));
    }
}
