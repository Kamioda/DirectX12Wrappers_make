﻿#pragma once
#include <wrl/client.h>
#include <string>
#include <functional>
#include <stdexcept>
template<class C> using MSComPtr = Microsoft::WRL::ComPtr<C>;

namespace meigetsusoft {
	namespace COM {
		template<class C>
		class ComPtr : public MSComPtr<C> {
		public:
			ComPtr(const std::function<HRESULT(MSComPtr<C>&)>& initFunction) {
				if (const HRESULT hr = initFunction(*this); FAILED(hr))
					throw std::runtime_error("Failed to init " + std::string(typeid(C).name) + "\nErrorCode : " + std::to_string(hr));
			}
		};
	}
}