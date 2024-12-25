#include "pch.h"
#include "UIUserControl.xaml.h"
#if __has_include("UIUserControl.g.cpp")
#include "UIUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::SharedComponent::implementation
{

    void UIUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
