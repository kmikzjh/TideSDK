/**
 * Appcelerator Kroll - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */

#ifndef _RUBY_LIST_H_
#define _RUBY_LIST_H_

#include "ruby_module.h"

namespace tide
{
	class KRubyList : public List
	{
	public:
		KRubyList(VALUE);
		virtual ~KRubyList();

		void Append(ValueRef value);
		unsigned int Size();
		ValueRef At(unsigned int index);
		void SetAt(unsigned int index, ValueRef value);
		bool Remove(unsigned int index);
		void Set(const char* name, ValueRef value);
		ValueRef Get(const char* name);
		SharedStringList GetPropertyNames();
		SharedString DisplayString(int);
		VALUE ToRuby();

	/*
	 * Determine if the given Ruby object equals this one
	 * by comparing these objects's identity e.g. equals?()
	 *  @param other the object to test
	 *  @returns true if objects have reference equality, false otherwise
	 */
	virtual bool Equals(ObjectRef);

	protected:
		VALUE list;
		AutoPtr<KRubyObject> object;
		DISALLOW_EVIL_CONSTRUCTORS(KRubyList);
	};
}
#endif
