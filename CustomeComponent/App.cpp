#include "pch.h"
#include "App.h"
#include "App.g.cpp"
#include "trace.h"
using namespace winrt;
using namespace Windows::UI::Xaml;
namespace winrt::CustomeComponent::implementation
{
    App::App()
    {
        RegisterTraceLogger();
        Initialize();
        AddRef();
        m_inner.as<::IUnknown>()->Release();
    }
    App::~App()
    {
        Close();
    }
}