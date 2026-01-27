# @47.com Email Platform - Database Schema Design

## 📋 Overview
A complete email management platform with advanced features including contacts, labels, drafts, sent items, spam filtering, and more.

---

## 🗂️ Core Tables

### 1. **users**
Stores user account information
```sql
CREATE TABLE users (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  email VARCHAR(255) UNIQUE NOT NULL,
  username VARCHAR(100) UNIQUE NOT NULL,
  password_hash VARCHAR(255) NOT NULL,
  first_name VARCHAR(100),
  last_name VARCHAR(100),
  profile_picture_url TEXT,
  signature TEXT DEFAULT '',
  theme 'light' | 'dark' DEFAULT 'light',
  language VARCHAR(10) DEFAULT 'en',
  two_factor_enabled BOOLEAN DEFAULT FALSE,
  recovery_codes TEXT[] DEFAULT '{}',
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  last_login TIMESTAMP,
  is_active BOOLEAN DEFAULT TRUE,
  storage_used_mb INTEGER DEFAULT 0,
  storage_limit_mb INTEGER DEFAULT 15000,
  INDEX(email),
  INDEX(username)
);
```

### 2. **emails**
Main email storage table
```sql
CREATE TABLE emails (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  sender_id UUID REFERENCES users(id) ON DELETE SET NULL,
  sender_email VARCHAR(255) NOT NULL,
  sender_name VARCHAR(255),
  recipients JSON NOT NULL DEFAULT '[]', -- {email, name, type: "to|cc|bcc"}
  subject VARCHAR(500) DEFAULT '',
  body TEXT,
  html_body TEXT,
  plain_text TEXT,
  is_read BOOLEAN DEFAULT FALSE,
  is_starred BOOLEAN DEFAULT FALSE,
  is_spam BOOLEAN DEFAULT FALSE,
  is_deleted BOOLEAN DEFAULT FALSE,
  is_draft BOOLEAN DEFAULT FALSE,
  is_sent BOOLEAN DEFAULT FALSE,
  message_id VARCHAR(255) UNIQUE,
  in_reply_to VARCHAR(255),
  thread_id UUID REFERENCES emails(id),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  received_at TIMESTAMP,
  scheduled_send_at TIMESTAMP,
  size_bytes INTEGER,
  encryption_key TEXT,
  INDEX(user_id),
  INDEX(thread_id),
  INDEX(is_read),
  INDEX(is_deleted),
  INDEX(created_at),
  INDEX(sender_email)
);
```

### 3. **attachments**
Email attachments storage
```sql
CREATE TABLE attachments (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  email_id UUID NOT NULL REFERENCES emails(id) ON DELETE CASCADE,
  file_name VARCHAR(255) NOT NULL,
  file_size_bytes INTEGER NOT NULL,
  mime_type VARCHAR(100),
  s3_key TEXT NOT NULL,
  s3_bucket VARCHAR(255) DEFAULT 'email-attachments',
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  virus_scan_status 'pending' | 'safe' | 'infected' DEFAULT 'pending',
  INDEX(email_id)
);
```

### 4. **labels**
User-defined email labels/folders
```sql
CREATE TABLE labels (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  name VARCHAR(100) NOT NULL,
  color_hex VARCHAR(7) DEFAULT '#0084FF',
  icon VARCHAR(50),
  is_system BOOLEAN DEFAULT FALSE,
  order_index INTEGER,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, name),
  INDEX(user_id)
);
```

### 5. **email_labels**
Junction table for emails and labels (many-to-many)
```sql
CREATE TABLE email_labels (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  email_id UUID NOT NULL REFERENCES emails(id) ON DELETE CASCADE,
  label_id UUID NOT NULL REFERENCES labels(id) ON DELETE CASCADE,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(email_id, label_id),
  INDEX(email_id),
  INDEX(label_id)
);
```

### 6. **contacts**
User contact book
```sql
CREATE TABLE contacts (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  email VARCHAR(255) NOT NULL,
  first_name VARCHAR(100),
  last_name VARCHAR(100),
  company VARCHAR(150),
  phone VARCHAR(20),
  profile_picture_url TEXT,
  notes TEXT,
  groups TEXT[] DEFAULT '{}',
  is_starred BOOLEAN DEFAULT FALSE,
  last_emailed_at TIMESTAMP,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, email),
  INDEX(user_id),
  INDEX(email)
);
```

### 7. **contact_groups**
Contact grouping system
```sql
CREATE TABLE contact_groups (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  name VARCHAR(100) NOT NULL,
  description TEXT,
  color_hex VARCHAR(7),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, name),
  INDEX(user_id)
);
```

### 8. **email_templates**
User email templates
```sql
CREATE TABLE email_templates (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  name VARCHAR(200) NOT NULL,
  subject VARCHAR(500),
  body TEXT NOT NULL,
  category VARCHAR(100),
  is_public BOOLEAN DEFAULT FALSE,
  variables JSON DEFAULT '[]',
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, name),
  INDEX(user_id)
);
```

### 9. **filters**
Email filtering rules
```sql
CREATE TABLE filters (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  name VARCHAR(200) NOT NULL,
  condition JSON NOT NULL, -- {from, subject, contains, size, etc}
  action JSON NOT NULL, -- {label_id, skip_inbox, archive, delete, mark_spam}
  is_active BOOLEAN DEFAULT TRUE,
  order_index INTEGER,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id)
);
```

### 10. **blocked_senders**
Blocked email addresses
```sql
CREATE TABLE blocked_senders (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  email VARCHAR(255) NOT NULL,
  reason TEXT,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, email),
  INDEX(user_id)
);
```

### 11. **forwarding_rules**
Email forwarding configuration
```sql
CREATE TABLE forwarding_rules (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  forward_from VARCHAR(255) NOT NULL,
  forward_to VARCHAR(255) NOT NULL,
  is_active BOOLEAN DEFAULT TRUE,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id)
);
```

### 12. **email_read_status**
Tracks email read/unread state per user
```sql
CREATE TABLE email_read_status (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  email_id UUID NOT NULL REFERENCES emails(id) ON DELETE CASCADE,
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  is_read BOOLEAN DEFAULT FALSE,
  read_at TIMESTAMP,
  UNIQUE(email_id, user_id),
  INDEX(user_id),
  INDEX(is_read)
);
```

### 13. **draft_metadata**
Metadata for draft management
```sql
CREATE TABLE draft_metadata (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  email_id UUID NOT NULL REFERENCES emails(id) ON DELETE CASCADE,
  auto_save_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  last_modified_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  is_autosave BOOLEAN DEFAULT TRUE,
  UNIQUE(user_id, email_id),
  INDEX(user_id)
);
```

### 14. **email_signatures**
Multiple email signatures per user
```sql
CREATE TABLE email_signatures (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  name VARCHAR(100) NOT NULL,
  html_content TEXT NOT NULL,
  is_default BOOLEAN DEFAULT FALSE,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, name),
  INDEX(user_id)
);
```

### 15. **spam_settings**
User spam filter preferences
```sql
CREATE TABLE spam_settings (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  filter_level 'low' | 'medium' | 'high' DEFAULT 'medium',
  filter_suspicious_images BOOLEAN DEFAULT TRUE,
  filter_unusual_characters BOOLEAN DEFAULT TRUE,
  filter_phishing BOOLEAN DEFAULT TRUE,
  auto_delete_spam_days INTEGER DEFAULT 30,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id),
  INDEX(user_id)
);
```

### 16. **activity_log**
User activity tracking
```sql
CREATE TABLE activity_log (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  action VARCHAR(100),
  resource_type VARCHAR(50),
  resource_id UUID,
  ip_address INET,
  user_agent TEXT,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id),
  INDEX(created_at)
);
```

### 17. **sessions**
User session management
```sql
CREATE TABLE sessions (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  token VARCHAR(500) UNIQUE NOT NULL,
  ip_address INET,
  user_agent TEXT,
  expires_at TIMESTAMP NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  last_accessed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  is_active BOOLEAN DEFAULT TRUE,
  INDEX(user_id),
  INDEX(token),
  INDEX(expires_at)
);
```

### 18. **notifications**
In-app notifications
```sql
CREATE TABLE notifications (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  type 'new_email' | 'scheduled_send' | 'storage_full' | 'security_alert' DEFAULT 'new_email',
  title VARCHAR(200),
  message TEXT,
  is_read BOOLEAN DEFAULT FALSE,
  data JSON,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  expires_at TIMESTAMP,
  INDEX(user_id),
  INDEX(is_read)
);
```

### 19. **scheduled_emails**
Scheduled email sending queue
```sql
CREATE TABLE scheduled_emails (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  email_id UUID NOT NULL REFERENCES emails(id) ON DELETE CASCADE,
  scheduled_for TIMESTAMP NOT NULL,
  status 'pending' | 'sent' | 'failed' DEFAULT 'pending',
  error_message TEXT,
  retry_count INTEGER DEFAULT 0,
  max_retries INTEGER DEFAULT 3,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id),
  INDEX(scheduled_for),
  INDEX(status)
);
```

### 20. **user_settings**
Additional user preferences and settings
```sql
CREATE TABLE user_settings (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL UNIQUE REFERENCES users(id) ON DELETE CASCADE,
  conversation_view BOOLEAN DEFAULT TRUE,
  preview_pane 'right' | 'bottom' | 'hidden' DEFAULT 'right',
  notification_sound BOOLEAN DEFAULT TRUE,
  notification_desktop BOOLEAN DEFAULT TRUE,
  notification_email BOOLEAN DEFAULT FALSE,
  auto_advance 'archive' | 'next' | 'conversation_list' DEFAULT 'conversation_list',
  undo_send_delay_seconds INTEGER DEFAULT 5,
  offline_mode ENABLED BOOLEAN DEFAULT FALSE,
  include_original_in_reply BOOLEAN DEFAULT TRUE,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id)
);
```

### 21. **ai_assistant_settings**
AI-powered email assistant preferences
```sql
CREATE TABLE ai_assistant_settings (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL UNIQUE REFERENCES users(id) ON DELETE CASCADE,
  is_enabled BOOLEAN DEFAULT TRUE,
  suggest_replies BOOLEAN DEFAULT TRUE,
  suggest_smart_compose BOOLEAN DEFAULT TRUE,
  tone_preference 'formal' | 'casual' | 'professional' DEFAULT 'professional',
  language VARCHAR(50) DEFAULT 'en',
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  INDEX(user_id)
);
```

### 22. **sender_addresses** (Optional for Business Plans)
Multiple sender addresses per user
```sql
CREATE TABLE sender_addresses (
  id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  email VARCHAR(255) NOT NULL,
  display_name VARCHAR(200),
  is_primary BOOLEAN DEFAULT FALSE,
  is_verified BOOLEAN DEFAULT FALSE,
  verification_token VARCHAR(255),
  verified_at TIMESTAMP,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, email),
  INDEX(user_id)
);
```

---

## 🔑 Key Relationships & Indexes

### Primary Indexes
- `users.id` - All user-related queries
- `emails.user_id` - Email retrieval
- `emails.thread_id` - Thread conversation grouping
- `email_labels.email_id` & `email_labels.label_id` - Label associations
- `contacts.user_id` - Contact management

### Search Indexes
- `emails.subject` - Full-text search
- `emails.body` - Full-text search
- `contacts.email` - Contact lookup
- `users.email` - User authentication

---

## 📊 Data Types & Constraints

| Table | Key Constraint | Notes |
|-------|---|---|
| users | UNIQUE(email, username) | Core authentication |
| emails | INDEX(user_id, created_at) | Fast inbox queries |
| labels | UNIQUE(user_id, name) | No duplicate labels |
| contacts | UNIQUE(user_id, email) | No duplicate contacts |
| sessions | UNIQUE(token) | Session validation |
| sender_addresses | UNIQUE(user_id, email) | Multiple sender support |

---

## 🚀 Performance Optimizations

### Query Patterns
1. **Inbox Query**: 
   ```sql
   SELECT e.* FROM emails e
   WHERE e.user_id = $1 AND e.is_deleted = false
   ORDER BY e.created_at DESC LIMIT 50
   ```

2. **Thread View**:
   ```sql
   SELECT e.* FROM emails e
   WHERE e.thread_id = $1
   ORDER BY e.created_at ASC
   ```

3. **Search**:
   ```sql
   SELECT e.* FROM emails e
   WHERE e.user_id = $1 
   AND (e.subject ILIKE $2 OR e.body ILIKE $2)
   ORDER BY e.created_at DESC
   ```

### Optimization Tips
- Add composite indexes: `(user_id, created_at)`, `(user_id, is_deleted)`
- Partition `emails` table by `user_id` for multi-tenancy
- Archive old emails (6+ months) to separate table
- Use Redis for session caching
- Implement full-text search on `emails(subject, body)`

---

## 🔐 Security Considerations

1. **Encryption at Rest**: Sensitive fields (password, recovery codes) use bcrypt
2. **Encryption in Transit**: All data over HTTPS/TLS
3. **End-to-End Encryption**: Optional for email body storage
4. **Access Control**: Row-level security on user_id
5. **Audit Logging**: activity_log tracks all important actions
6. **Session Management**: Secure token storage with expiration

---

## 📈 Scalability Notes

- **Database**: PostgreSQL with connection pooling
- **Attachments**: Store in S3 with references in DB
- **Full-text Search**: Consider Elasticsearch for large-scale
- **Caching**: Redis for sessions and frequently accessed data
- **Queue**: Background job queue for email sending (Bull, Celery)

---

## 🎯 Feature Roadmap

### Phase 1 (MVP)
- User authentication
- Send/receive emails
- Basic inbox management
- Contacts management

### Phase 2
- Labels & folders
- Email templates
- Search functionality
- Attachments

### Phase 3
- Email filters & automation
- Scheduled sending
- Spam detection
- Multiple signatures

### Phase 4 (Premium)
- AI email assistant
- Advanced encryption
- Multiple sender addresses
- Team collaboration

---

## 📝 Notes

- All timestamps use UTC
- UUIDs for primary keys (better for distributed systems)
- Soft deletes recommended for emails (is_deleted flag)
- Consider data retention policies (GDPR compliance)
- Email body can be stored as both HTML and plain text
- Thread_id can reference its own id for threading conversations
