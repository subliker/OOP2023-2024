#include "cl_base.h"

// ����� �������� ����� ����� �������� �������� ������� � ������������ �������� �������
void cl_base::set_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER   p_ob_handler) {
	o_sh* p_value;
	for (unsigned int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->p_signal == p_signal &&
			connects[i]->p_cl_base == p_object &&
			connects[i]->p_handler == p_ob_handler)
		{
			return;
		}
	}

	p_value = new o_sh();                 // �������� ������� ��������� ���
	// �������� ���������� � ����� �����
	p_value->p_signal = p_signal;
	p_value->p_cl_base = p_object;
	p_value->p_handler = p_ob_handler;

	connects.push_back(p_value);          // ���������� ����� �����                 
}

// ����� ������ ������� �� �������� ������� � ��������� ��������� ����������
void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& s_command) {
	TYPE_HANDLER   p_handler;
	cl_base* p_object;
	// ���� ��������
	if (this->state == 0) return;

	(this->*p_signal) (s_command);  // ����� ������ �������

	for (unsigned int i = 0; i < connects.size(); i++) // ���� �� ���� ������������
	{
		if (connects[i]->p_signal == p_signal)      // ����������� ����������� �����������
		{
			p_object = connects[i]->p_cl_base;
			if (p_object->state == 0) continue;

			p_handler = connects[i]->p_handler;

			(p_object->*p_handler) (s_command);      // ����� ������ �����������
		}
	}
}

// ����� �������� (�������) ����� ����� �������� �������� ������� � ������������ �������� �������
void cl_base::break_connection(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_handler) {
	for (auto i = connects.begin(); i != connects.end(); i++) {
		o_sh* c = *i;
		if (c->p_cl_base == p_object &&
			c->p_handler == p_ob_handler &&
			c->p_signal == p_signal) {
			connects.erase(i);
			delete c;
			return;
		}
	}
}
