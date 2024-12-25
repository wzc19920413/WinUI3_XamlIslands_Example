#pragma once

#include "UIUserControl.g.h"

namespace winrt::SharedComponent::implementation
{
    struct UIUserControl : UIUserControlT<UIUserControl>
    {
        UIUserControl()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void ClickHandler(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SharedComponent::factory_implementation
{
    struct UIUserControl : UIUserControlT<UIUserControl, implementation::UIUserControl>
    {
    };
}
