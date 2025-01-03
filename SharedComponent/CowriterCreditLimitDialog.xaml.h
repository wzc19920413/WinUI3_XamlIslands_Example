#pragma once

#include "CowriterCreditLimitDialog.g.h"

namespace winrt::SharedComponent::implementation
{
    struct CowriterCreditLimitDialog : CowriterCreditLimitDialogT<CowriterCreditLimitDialog>
    {
        CowriterCreditLimitDialog()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SharedComponent::factory_implementation
{
    struct CowriterCreditLimitDialog : CowriterCreditLimitDialogT<CowriterCreditLimitDialog, implementation::CowriterCreditLimitDialog>
    {
    };
}
